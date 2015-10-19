#ifndef PGMACLAYER_H
#define PGMACLAYER_H

#include <omnetpp.h>

#include "mac_types.h"
#include "mac_pib.h"
#include "base/utils/MiXiMDefs.h"
#include "base/modules/BaseMacLayer.h"
#include "glider/radio/utils/NetwToMacInfo.h"

#define macEV debugEV<<"[MAC] "

class MIXIM_API GliderMacLayer: public BaseMacLayer
{
public:

	/** @brief Initializes the module and some variables. */
	virtual void initialize(int);

	/** @brief Deletes all dynamically allocated objects of the module. */
	virtual void finish();

	/** @brief Handles self messages such as timers. */
	virtual void handleSelfMsg(cMessage*);

	/** @brief Handles messages from lower layer. */
	virtual void handleLowerMsg(cMessage*);

	/** @brief Handles messages from upper layer. */
	virtual void handleUpperMsg(cMessage*);

	/** @brief Handles messages from upper layer. */
	virtual void handleLowerControl(cMessage*);

protected:

	/** Types for FSM states. */
	typedef enum t_mac_fsm_state
	{
		STATE_IDLE = 1,
		STATE_BACKOFF,
		STATE_CCA,
		STATE_TRANSMIT_FRAME,
		STATE_WAIT_FOR_ACK,
		STATE_WAIT_SIFS,
		STATE_TRANSMIT_ACK
	} t_mac_fsm_state;

	/** Types for FSM events. */
	typedef enum t_mac_fsm_event
	{
		EVENT_TRANSMIT_FRAME = 1,
		EVENT_TIMER_BACKOFF,
		EVENT_TIMER_CCA,
		EVENT_FRAME_TRANSMITTED,
		EVENT_FRAME_RECEIVED,
		EVENT_TRANSMIT_ACK,
		EVENT_TIMER_SIFS,
		EVENT_ACK_TIMEOUT,
		EVENT_ACK_RECEIVED
	} t_mac_fsm_event;

	/** Types for timer messages. */
	typedef enum t_mac_timer
	{
		TIMER_NULL = 0,
		TIMER_BACKOFF,
		TIMER_CCA,
		TIMER_SIFS,
		TIMER_WAIT_FOR_ACK,
		TIMER_TURNAROUND
	} t_mac_timer;

	/** Functions for FSM processing. */
	void processFSM(t_mac_fsm_event event);
	void updateFsmState(t_mac_fsm_state newFsmState);
	void updateStateIdle(t_mac_fsm_event event);
	void updateStateBackoff(t_mac_fsm_event event);
	void updateStateCCA(t_mac_fsm_event event);
	void updateStateTransmitFrame(t_mac_fsm_event event);
	void updateStateWaitAck(t_mac_fsm_event event);
	void updateStateWaitSifs(t_mac_fsm_event event);
	void updateStateTransmitAck(t_mac_fsm_event event);
	void throwFsmError(t_mac_fsm_event event);
	void startTimer(t_mac_timer timer);
	virtual simtime_t scheduleBackoff();

	/** Functions for WPAN management. */
	void wpan_init();
	void wpan_handle_rx();
	void wpan_handle_frame();
	void radio_send_variable_packet(uint8_t*, uint16_t);
	void upper_layer_handler(status_type, char*);

	void wpan_data_request(cMessage*);
	void wpan_purge_request();
	void wpan_associate_request();
	void wpan_disassociate_request();
	void wpan_get_request();
	void wpan_reset_request();
	void wpan_scan_request();
	void wpan_set_request();
	void wpan_start_request();
	void wpan_poll_request();

	void wpan_data_indication();
	void wpan_associate_indication();
	void wpan_disassociate_indication();
	void wpan_beacon_notify_indication();
	void wpan_comm_status_indication();
	void wpan_orphan_indication();
	void wpan_sync_loss_indication();

	void wpan_associate_response();
	void wpan_orphan_response();

	void wpan_data_confirm(status_type);
	void wpan_purge_confirm();
	void wpan_associate_confirm();
	void wpan_disassociate_confirm();
	void wpan_get_confirm();
	void wpan_reset_confirm();
	void wpan_scan_confirm();
	void wpan_set_confirm();
	void wpan_start_confirm();
	void wpan_poll_confirm();

protected:

	char mac_frame_tx[255];
	char mac_frame_rx[255];
	char mac_frame_ack[255];
	char rf_packet_rx_buf[255];

	/** @brief Pointer for timer messages. */
	cMessage * backoffTimer, *ccaTimer, *txTimer, *sifsTimer, *rxAckTimer, *turnaroundTimer;

	/** @brief Keep track of MAC state. */
	t_mac_fsm_state fsmState;

	/** @brief Minimum period until next tx attempt after short frame. */
	simtime_t sifs_time;

	/** @brief Minimum period until next tx attempt after long frame. */
	simtime_t lifs_time;

	/** @brief The amount of time the MAC waits for the ACK of a packet. */
	simtime_t ack_wait_time;

	/** @brief Maximum period for CCA. */
	simtime_t cca_time;

	/** @brief Maximum time to switch radio between Rx and Tx state. */
	simtime_t a_turnaround_time;

	/** @brief Maximum number of backoffs before frame drop. */
	int macMaxCSMABackoffs;

	/** @brief Maximum number of frame retransmissions without ack. */
	unsigned int macMaxFrameRetries;

	/** @brief Base time unit for calculating backoff durations. */
	simtime_t backoff_period;

	/** @brief Initial contention window size. */
	double initialCW;

	/** @brief The power (in mW) to transmit with. */
	double txPower;

	/** @brief Number of backoffs performed until now for current frame. */
	int NB;

	/** @brief Number of tx attempts for current packent. */
	unsigned int txAttempts;

	/** @brief Bitrate at which we transmit. */
	double bitrate;

	/** @brief Publish dropped packets nic wide. */
	int nicId;

	/** @brief Is MAC layer in promiscous mode? */
	bool macPromiscuousMode;

	/** @brief Already sending an ACK? */
	bool sendingAck;

};

#endif
