#include "GliderMacLayer.h"

#include "base/utils/FWMath.h"
#include "base/utils/FindModule.h"
#include "base/connectionManager/BaseConnectionManager.h"
#include "base/modules/BaseMacLayer.h"
#include "base/phyLayer/BaseDecider.h"
#include "base/phyLayer/BasePhyLayer.h"
#include "base/phyLayer/PhyToMacControlInfo.h"
#include "glider/radio/utils/NetwToMacInfo.h"
#include "glider/radio/utils/MacToNetwInfo.h"
#include "MacFrame_m.h"

Define_Module(GliderMacLayer);

void GliderMacLayer::initialize(int stage)
{
	BaseMacLayer::initialize(stage);

	if (stage == 0)
	{
		wpan_init();

		debug = true;
		nicId = getParentModule()->getId();
		bitrate = par("bitrate");
		txPower = par("txPower").doubleValue();

		// initialize the timers
		backoffTimer = new cMessage("timer-backoff");
		ccaTimer = new cMessage("timer-cca");
		sifsTimer = new cMessage("timer-sifs");
		rxAckTimer = new cMessage("timer-rxAck");
		turnaroundTimer = new cMessage("timer-turnaround");

		sendingAck = false;

		debugEV << "a_turnaround_time = " << a_turnaround_time << endl;
		debugEV << "sifs_time = " << sifs_time << endl;
		debugEV << "lifs_time = " << lifs_time << endl;
		debugEV << "ack_wait_time = " << ack_wait_time << endl;
		debugEV << "cca_time = " << cca_time << endl;
	}
	else if (stage == 1)
	{
		BaseConnectionManager* cc = getConnectionManager();

		if (cc->hasPar("pMax") && txPower > cc->par("pMax").doubleValue())
			opp_error("TranmitterPower can't be bigger than pMax in ConnectionManager! "
					"Please adjust your omnetpp.ini file accordingly");

		debugEV << "bitrate = " << bitrate << " txpower = " << txPower << endl;
		debugEV << "finished GliderMacLayer init stage 1." << endl;
	}
}

void GliderMacLayer::finish()
{
	cancelAndDelete(turnaroundTimer);
	cancelAndDelete(backoffTimer);
	cancelAndDelete(rxAckTimer);
	cancelAndDelete(sifsTimer);
	cancelAndDelete(ccaTimer);

	free(mac_frame_rx);
	free(mac_frame_tx);
	free(mac_frame_ack);
	free(rf_packet_rx_buf);
}

/*
 * Binds timers to events and executes FSM.
 */
void GliderMacLayer::handleSelfMsg(cMessage *msg)
{
	if (msg == backoffTimer)
		processFSM(EVENT_TIMER_BACKOFF);
	else if (msg == ccaTimer)
		processFSM(EVENT_TIMER_CCA);
	else if (msg == sifsTimer)
		processFSM(EVENT_TIMER_SIFS);
	else if (msg == rxAckTimer)
		processFSM(EVENT_ACK_TIMEOUT);
	else if (msg == turnaroundTimer)
		radio_send_variable_packet((uint8_t*)mac_frame_tx, strlen(mac_frame_tx));
	else
		macEV << "FSM unknown timer fired." << endl;
}

/**
 * @brief Checks the primitive type of the passed message and generates the
 *        appropriate FSM event.
 */
void GliderMacLayer::handleUpperMsg(cMessage *msg)
{
	switch (msg->getKind())
	{
	case primitive_type::DATA_REQUEST:
		macEV << "received DATA request from upper layer." << endl;
		wpan_data_request(msg);
		break;
	default:
		return;
	}
}

/**
 * @brief Checks if MAC layer is in promiscuous mode (second level filter), if the
 *        message is a broadcast message or if the message destination address is
 *        the local address (third level filter). Checks frame type if successfull,
 *        passes the message to the FSM and generates the appropriate event.
 */
void GliderMacLayer::handleLowerMsg(cMessage *msg)
{
	MacFrame *pMacFrame = static_cast<MacFrame *>(msg);
	struct frame_control_field *cf;
	uint8_t index = sizeof(struct frame_control_field);
	cf = (struct frame_control_field*) rf_packet_rx_buf;

	cf->frame_type = pMacFrame->getFrame_type();
	cf->security_enabled = 0;
	cf->frame_pending = 0;
	cf->ar = pMacFrame->getAckRequest();
	cf->pan_id_compression = 0;
	cf->dest_addressing_mode = EXTENDED_ADDRESS;
	cf->src_addressing_mode = EXTENDED_ADDRESS;

	rf_packet_rx_buf[index] = pMacFrame->getSequenceNumber();
	rf_packet_rx_buf[index + 2] = pMacFrame->getSrcAddr();
	rf_packet_rx_buf[index + 10] = pMacFrame->getDestAddr();

	delete(msg);
	wpan_handle_rx();
}

void GliderMacLayer::handleLowerControl(cMessage *msg)
{
	if (msg->getKind() == MacToPhyInterface::TX_OVER)
	{
		macEV << "received control message TX_OVER from lower layer." << endl;
		processFSM(EVENT_FRAME_TRANSMITTED);
	}
	else if (msg->getKind() == MacToPhyInterface::RADIO_SWITCHING_OVER)
	{
		macEV << "received control message RADIO_SWITCHING_OVER from lower layer." << endl;
	}
	else
	{
		macEV << "received unknown control message from lower layer." << endl;
	}
	delete(msg);
}

/**
 * Methods for WPAN management.
 */
void GliderMacLayer::wpan_init()
{
	// initialize timer values
	simtime_t phySymbolTime = 0.00005;
	a_turnaround_time = aTurnaroundTime * phySymbolTime;
	sifs_time = macSIFSPeriod * phySymbolTime;
	lifs_time = macLIFSPeriod * phySymbolTime;
	ack_wait_time = macAckWaitDuration * phySymbolTime;
	cca_time = phyCCADuration * phySymbolTime;
	backoff_period = aUnitBackoffPeriod * phySymbolTime;

	// initialize control variables
	macPromiscuousMode = true;
	fsmState = STATE_IDLE;
	txAttempts = 0;
}

void GliderMacLayer::wpan_data_request(cMessage* msg)
{
	struct frame_control_field *cf;
	uint8_t index = sizeof(struct frame_control_field);

	cf = (struct frame_control_field*)mac_frame_tx;

	cf->frame_type = DATA_FRAME;
	cf->security_enabled = 0;
	cf->frame_pending = 0;
	cf->ar = 0;
	cf->pan_id_compression = 0;
	cf->dest_addressing_mode = EXTENDED_ADDRESS;
	cf->src_addressing_mode = EXTENDED_ADDRESS;

	mac_frame_tx[index] = macDSN;
	mac_frame_tx[index + 10] = macExtendedAddress;
	mac_frame_tx[index + 18] = '\0';

	macEV << "frame: " << strlen(mac_frame_tx) << endl;

	processFSM(EVENT_TRANSMIT_FRAME);
}

void GliderMacLayer::wpan_data_confirm(status_type status)
{
	upper_layer_handler(status, mac_frame_tx);
}

void GliderMacLayer::wpan_data_indication()
{
	upper_layer_handler(SUCCESS, mac_frame_rx);
}

void GliderMacLayer::wpan_handle_rx()
{
	if (sendingAck)
	{
		macEV << "received frame but already processing one." << endl;
		return;
	}

	memcpy(mac_frame_rx, rf_packet_rx_buf, strlen(rf_packet_rx_buf));
	uint64_t destAddress = mac_frame_rx[sizeof(struct frame_control_field) + 10];
	uint16_t dsn = mac_frame_rx[sizeof(struct frame_control_field)];

	if (macPromiscuousMode || destAddress == BROADCAST_ADDRESS || destAddress == macExtendedAddress)
	{
		if (mac_frame_rx[5])
		{
			macEV << "received frame with AR and creating ACK frame." << endl;
			struct frame_control_field *fc = (struct frame_control_field *)mac_frame_rx;
			sendingAck = true;

			fc = (struct frame_control_field*) mac_frame_ack;

			fc->frame_type = ACK_FRAME;
			fc->security_enabled = false;
			fc->frame_pending = false;
			fc->ar = false;
			fc->pan_id_compression = false;
			fc->dest_addressing_mode = NO_ADDRESS;
			fc->src_addressing_mode = NO_ADDRESS;

			mac_frame_ack[sizeof(struct frame_control_field)] = dsn;

			processFSM(EVENT_TRANSMIT_ACK);
		}
		else
		{
			wpan_handle_frame();
		}
	}
}

void GliderMacLayer::wpan_handle_frame()
{
	switch ((frame_type)mac_frame_rx[0])
	{
	case DATA_FRAME:
		macEV << "handling DATA frame." << endl;
		wpan_data_indication();
		break;
	case ACK_FRAME:
		macEV << "handling ACK frame." << endl;
		processFSM(EVENT_ACK_RECEIVED);
		break;
	case BEACON_FRAME:
		macEV << "handling BEACON frame." << endl;
		break;
	case CMD_FRAME:
		macEV << "handling COMMAND frame." << endl;
		break;
	default:
		break;
	}
}

/**
 * Methods for the FSM.
 */
void GliderMacLayer::processFSM(t_mac_fsm_event event)
{
	switch (fsmState)
	{
	case STATE_IDLE:
		updateStateIdle(event);
		break;
	case STATE_BACKOFF:
		updateStateBackoff(event);
		break;
	case STATE_CCA:
		updateStateCCA(event);
		break;
	case STATE_TRANSMIT_FRAME:
		updateStateTransmitFrame(event);
		break;
	case STATE_WAIT_FOR_ACK:
		updateStateWaitAck(event);
		break;
	case STATE_WAIT_SIFS:
		updateStateWaitSifs(event);
		break;
	case STATE_TRANSMIT_ACK:
		updateStateTransmitAck(event);
		break;
	default:
		macEV << "FSM reached unknown state " << fsmState << "!" << endl;
		break;
	}
}

void GliderMacLayer::updateStateIdle(t_mac_fsm_event event)
{
	switch (event)
	{
	case EVENT_TRANSMIT_FRAME:
		NB = 0;
		startTimer(TIMER_BACKOFF);
		updateFsmState(STATE_BACKOFF);
		macEV << "FSM is in backoff state now." << endl;
		break;
	case EVENT_TRANSMIT_ACK:
		phy->setRadioState(Radio::TX);
		startTimer(TIMER_SIFS);
		updateFsmState(STATE_WAIT_SIFS);
		break;
	default:
		throwFsmError(event);
		break;
	}
}

void GliderMacLayer::updateStateBackoff(t_mac_fsm_event event)
{
	switch (event)
	{
	case EVENT_TIMER_BACKOFF:
		phy->setRadioState(Radio::RX);
		startTimer(TIMER_CCA);
		updateFsmState(STATE_CCA);
		macEV << "FSM requesting CCA" << endl;
		break;
	case EVENT_TRANSMIT_ACK:
		cancelEvent(backoffTimer);
		wpan_data_confirm(CHANNEL_ACCESS_FAILURE);
		phy->setRadioState(Radio::TX);
		startTimer(TIMER_SIFS);
		updateFsmState(STATE_WAIT_SIFS);
		break;
	default:
		throwFsmError(event);
		break;
	}
}

void GliderMacLayer::updateStateCCA(t_mac_fsm_event event)
{
	switch (event)
	{
	case EVENT_TIMER_CCA:
		if (phy->getChannelState().isIdle())
		{
			phy->setRadioState(Radio::TX);
			startTimer(TIMER_TURNAROUND);
			updateFsmState(STATE_TRANSMIT_FRAME);
			macEV << "FSM transmitting frame" << endl;
		}
		else
		{
			NB = NB + 1;
			if (NB > macMaxCSMABackoffs)
			{
				macEV << "FSM reached maximum number of backoffs." << endl;
				wpan_data_confirm(status_type::CHANNEL_ACCESS_FAILURE);
				updateFsmState(STATE_IDLE);
			}
			else
			{
				updateFsmState(STATE_BACKOFF);
				startTimer(TIMER_BACKOFF);
			}
		}
		break;
	case EVENT_TRANSMIT_ACK:
		cancelEvent(ccaTimer);
		wpan_data_confirm(CHANNEL_ACCESS_FAILURE);
		phy->setRadioState(Radio::TX);
		startTimer(TIMER_SIFS);
		updateFsmState(STATE_TRANSMIT_ACK);
		break;
	default:
		throwFsmError(event);
		break;
	}
}

void GliderMacLayer::updateStateTransmitFrame(t_mac_fsm_event event)
{
	switch (event)
	{
	case EVENT_FRAME_TRANSMITTED:
		macEV << "FSM transmission over" << endl;
		phy->setRadioState(Radio::RX);
		if (mac_frame_tx[5])
		{
			macEV << "waiting for ACK." << endl;
			startTimer(TIMER_WAIT_FOR_ACK);
			updateFsmState(STATE_WAIT_FOR_ACK);
		}
		else
		{
			macEV << "FSM confirm transmission to upper layer." << endl;
			wpan_data_confirm(status_type::SUCCESS);
			updateFsmState(STATE_IDLE);
		}
		break;
	default:
		throwFsmError(event);
		break;
	}
}

void GliderMacLayer::updateStateWaitAck(t_mac_fsm_event event)
{
	switch (event) {
	case EVENT_ACK_RECEIVED:
		if(rxAckTimer->isScheduled())
		cancelEvent(rxAckTimer);
		wpan_data_confirm(status_type::SUCCESS);
		updateFsmState(STATE_IDLE);
		break;
	case EVENT_ACK_TIMEOUT:
		wpan_data_confirm(status_type::NO_ACK);
		updateFsmState(STATE_IDLE);
		break;
	default:
		throwFsmError(event);
		break;
	}
}

void GliderMacLayer::updateStateWaitSifs(t_mac_fsm_event event)
{
	switch (event)
	{
	case EVENT_TIMER_SIFS:
		radio_send_variable_packet((uint8_t*)mac_frame_ack, sizeof(mac_frame_ack));
		updateFsmState(STATE_TRANSMIT_ACK);
		break;
	default:
		throwFsmError(event);
		break;
	}
}

void GliderMacLayer::updateStateTransmitAck(t_mac_fsm_event event)
{
	switch (event)
	{
	case EVENT_FRAME_TRANSMITTED:
		macEV << "FSM transmitted ACK sucessfully." << endl;
		phy->setRadioState(Radio::RX);
		updateFsmState(STATE_IDLE);
		sendingAck = false;
		wpan_handle_frame();
		break;
	default:
		throwFsmError(event);
		break;
	}
}

void GliderMacLayer::updateFsmState(t_mac_fsm_state newFsmState)
{
	fsmState = newFsmState;
}

/*
 * Called by the FSM machine when an unknown transition is requested.
 */
void GliderMacLayer::throwFsmError(t_mac_fsm_event event)
{
	macEV<< "FSM Error received unknown event " << event << " in state " << fsmState << "!" << endl;
}

/*
 * @brief Calculates the appropriate time for passed timer type and calls
 *        the scheduling function.
 */
void GliderMacLayer::startTimer(t_mac_timer timer)
{
	switch (timer)
	{
	case TIMER_BACKOFF:
		scheduleAt(scheduleBackoff(), backoffTimer);
		break;
	case TIMER_CCA:
		scheduleAt(simTime() + a_turnaround_time + cca_time, ccaTimer);
		break;
	case TIMER_SIFS:
		scheduleAt(simTime() + sifs_time, sifsTimer);
		break;
	case TIMER_WAIT_FOR_ACK:
		scheduleAt(simTime() + ack_wait_time, rxAckTimer);
		break;
	case TIMER_TURNAROUND:
		scheduleAt(simTime() + a_turnaround_time, turnaroundTimer);
		break;
	default:
		macEV << "FSM unknown timer requested to start " << timer << endl;
	}
}

/*
 * @brief Calculates the backoff delay for the current transmission as a function
 *        of the number of previously scheduled backoff delays (NB) and the default
 *        backoff period (aUnitBackoffPeriod).
 */
simtime_t GliderMacLayer::scheduleBackoff()
{
	int BE = std::min(macMinBE + NB, macMaxBE);
	int max_value = (1 << BE) - 1;
	int random_value = intuniform(0, max_value, 0);

	simtime_t backoffTime = random_value * backoff_period;

	macEV << "scheduled backoff delay is " << backoffTime << endl;

	return backoffTime + simTime();
}

/**
 * @brief Converts the passed MAC frame structure to a MacFrame object and sends it down to the lower layer.
 **/
void GliderMacLayer::radio_send_variable_packet(uint8_t *packet, uint16_t length)
{
	MacFrame *pMacFrame = new MacFrame("MAC Frame");

	pMacFrame->setFrame_type((frame_type)packet[0]);
	pMacFrame->setAckRequest(packet[5]);
	pMacFrame->setSequenceNumber(packet[sizeof(struct frame_control_field)]);
	pMacFrame->setSrcAddr(packet[sizeof(struct frame_control_field)] + 2);
	pMacFrame->setDestAddr(packet[sizeof(struct frame_control_field)] + 10);

	simtime_t duration = (length + phyHeaderLength) / bitrate;
	setDownControlInfo(pMacFrame, createSignal(simTime(), duration, txPower, bitrate));
	sendDown(pMacFrame);
	macEV << "sending down MAC frame" << endl;
}

void GliderMacLayer::upper_layer_handler(status_type status, char* msg)
{
	cMessage *pMessage = new cMessage(msg);
	MacToNetwInfo *pInfo = MacToNetwInfo::setControlInfo(pMessage);
	pInfo->setStatus(status);
	sendUp(pMessage);
}

