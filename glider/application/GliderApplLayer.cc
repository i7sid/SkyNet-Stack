#include <fstream>
#include <iostream>
#include <string>

#include "GliderApplLayer.h"
#include "GliderNetworkPkt_m.h"

#include "glider/radio/utils/MacToNetwInfo.h"
#include "base/utils/SimpleAddress.h"
#include "base/utils/FindModule.h"
#include "base/utils/FWMath.h"

#include "glider/radio/utils/NetwToMacInfo.h"
#include "glider/mobility/GliderMobility.h"
#include "mac_types.h"

using std::endl;

Define_Module(GliderApplLayer);

void GliderApplLayer::initialize(int stage)
{
	EV << "Initializing GliderApplLayer stage " << stage << "of node[" << getParentModule()->getIndex() << "]" << endl;

	BaseApplLayer::initialize(stage);

	if (stage == 0)
	{
		debug = true;
		txTimer = new cMessage("delay-timer", SEND_BROADCAST_TIMER);
		scheduleAt(simTime()+intuniform(0, 10, 0),txTimer);
	}
}

void GliderApplLayer::handleSelfMsg(cMessage *msg)
{
	switch (msg->getKind())
	{
	case SEND_BROADCAST_TIMER:
		sendBroadcast("message", FWMath::dBm2mW(20));
		scheduleAt(simTime()+5, txTimer);
		break;
	default:
		EV << "node[" << getParentModule()->getIndex() << "] Unkown selfmessage! -> delete, kind: " << msg->getKind() << endl;
		break;
	}
}

/**
 * There are two kinds of messages that can arrive at this module: The
 * first (kind = BROADCAST_MESSAGE) is a broadcast packet from a
 * neighbor node to which we have to send a reply (if bSendReply is true). The second (kind =
 * BROADCAST_REPLY_MESSAGE) is a reply to a broadcast packet that we
 * have send and just causes some output before it is deleted
 */
void GliderApplLayer::handleLowerMsg(cMessage* msg)
{
	applEV << "received DATA message from lower layer." << endl;
	delete(msg);
}

void GliderApplLayer::handleLowerControl(cMessage* msg)
{
	MacToNetwInfo* info = static_cast<MacToNetwInfo*>(msg->getControlInfo());
	switch (info->getStatus())
	{
	case status_type::SUCCESS:
		applEV << "received control message with status SUCCESS from lower layer." << endl;
		break;
	case status_type::NO_ACK:
		applEV << "received control message with status NO_ACK from lower layer." << endl;
		break;
	case status_type::CHANNEL_ACCESS_FAILURE:
		applEV << "received control message with status CHANNEL_ACCESS_FAILURE from lower layer." << endl;
		break;
	default:
		applEV << "received unknown control message from lower layer." << endl;
	}
	delete(msg);
}

void GliderApplLayer::sendBroadcast(const char* name, double txPower_mW)
{
	GliderNetworkPkt *pkt = new GliderNetworkPkt(name, BROADCAST_MESSAGE);
	pkt->setDestAddr(LAddress::L3BROADCAST);
	// we use the host modules getIndex() as a appl address
	pkt->setSrcAddr(getParentModule()->getIndex());
	pkt->setBitLength(headerLength);

	// set the control info to tell the network layer the layer 3
	// address
	NetwToMacInfo* pInfo = new NetwToMacInfo();
	pInfo->setDstAddr(LAddress::L2BROADCAST);
	pInfo->setTxPower(txPower_mW);
	pInfo->setAckTX(false);
	pkt->setControlInfo(pInfo);
	pkt->setKind(DATA_FRAME);

	applEV << "Sending broadcast packet with txPower = " << txPower_mW << "." << endl;
	sendDown(pkt);
}

void GliderApplLayer::finish(void)
{
	EV << "node[" << getParentModule()->getIndex() << "] App Layer finish" << endl;
	cancelAndDelete(txTimer);
}
