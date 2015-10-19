#ifndef MACTONETWINFO_H
#define MACTONETWINFO_H

#include <omnetpp.h>

#include "base/utils/MiXiMDefs.h"
#include "base/utils/SimpleAddress.h"
#include "mac_types.h"

/**
 *
 * @brief Structure to pass parameters from the MAC to the network layer.
 *
 **/
class MIXIM_API MacToNetwInfo: public cObject
{

protected:

	/** @brief Request type of the attached message. */
	primitive_type requestType;

	/** @brief Source addressing mode for this MPDU. */
	addressing_mode SrcAddrMode;
	/** @brief PAN identifier of the source device. */
	int SrcPANId;
	/** @brief Short address of the source device. */
	LAddress::L2Type SrcAddr;
	/** @brief Destination addressing mode for this MPDU. */
	addressing_mode DstAddrMode;
	/** @brief PAN identifier of the destination device. */
	int DstPANId;
	/** @brief Short address of the destination device. */
	LAddress::L2Type DstAddr;
	/** @brief Number of octets contained in the MSDU. */
	int msduLength;
	/** @brief LQI value measured during reception of the MPDU. */
	int mpduLinkQuality;
	/** @brief Data Sequence Number of the received frame. */
	int DSN;
	/** @brief Time at which the data were received. */
	int Timestamp;
	/** @brief Security level to be used. */
	int SecurityLevel;
	/** @brief The mode used to identify the key to be used. */
	int KeyIdMode;
	/** @brief The originator of the key to be used. */
	int KeySource;
	/** @brief The index of the key to be used. */
	int KeyIndex;
	/** @brief The preamble symbol repetitions of the UWB PHY. */
	int UWBPreambleSymbolRepetitions;
	/** @brief Indicates the data rate for UWB and CSS PHYs. */
	int DataRate;
	/** @brief Count of time units at the beginning of a ranging exchange. */
	uint RangingCounterStart;
	/** @brief Count of time units at the end of a ranging exchange. */
	uint RangingCounterStop;
	/** @brief Count of time units over which tracking offset was measured. */
	int RangingTrackingInterval;
	/** @brief Count of time units slipped or advanced by radio tracking system. */
	int RangingOffset;
	/** @brief Characterization of confidence level for ranging. */
	int RangingFOM;
	/** @brief Status type of the attached message. */
	status_type status;

public:

	/** @brief Default constructor. */
	MacToNetwInfo() : cObject()
			, requestType(DATA_INDICATION)
			, SrcAddrMode(EXTENDED_ADDRESS)
			, SrcPANId(0)
			, SrcAddr(0)
			, DstAddrMode(EXTENDED_ADDRESS)
			, DstPANId(0)
			, DstAddr(0)
			, msduLength(0)
			, mpduLinkQuality(0)
			, DSN(0)
			, Timestamp(0)
			, SecurityLevel(0)
			, KeyIdMode(0)
			, KeySource(0)
			, KeyIndex(0)
			, UWBPreambleSymbolRepetitions(0)
			, DataRate(0)
			, RangingCounterStart(0)
			, RangingCounterStop(0)
			, RangingTrackingInterval(0)
			, RangingOffset(0)
			, RangingFOM(0)
			, status(SUCCESS)

	{}

	/** @brief Destructor. */
	~MacToNetwInfo()
	{}

	/** @brief Get method for the request type. */
	const primitive_type& getRequestType() const
	{
		return requestType;
	}

	/** @brief Set method for the request type. */
	void setRequestType(primitive_type type)
	{
		requestType = type;
	}

	/** @brief Get method for the source addressing mode. */
	const addressing_mode& getSrcAddrMode() const
	{
		return SrcAddrMode;
	}

	/** @brief Set method for the source addressing mode. */
	void setSrcAddrMode(addressing_mode mode)
	{
		SrcAddrMode = mode;
	}

	/** @brief Get method for the source PAN identifier. */
	const int getSrcPanId()
	{
		return SrcPANId;
	}

	/** @brief Set method for the source PAN identifier. */
	void setSrcPanId(int id)
	{
		SrcPANId = id;
	}

	/** @brief Get method for the short source address. */
	const LAddress::L2Type& getSrcAddr() const
	{
		return SrcAddr;
	}

	/** @brief Set method for the short source address. */
	void setSrcAddr(int addr)
	{
		SrcAddr = addr;
	}

	/** @brief Get method for the destination addressing mode. */
	const addressing_mode& getDstAddrMode() const
	{
		return DstAddrMode;
	}

	/** @brief Set method for the destination addressing mode. */
	void setDstAddrMode(addressing_mode mode)
	{
		DstAddrMode = mode;
	}

	/** @brief Get method for the destination PAN identifier. */
	const int getDstPanId()
	{
		return DstPANId;
	}

	/** @brief Set method for the destination PAN identifier. */
	void setDstPanId(int id)
	{
		DstPANId = id;
	}

	/** @brief Get method for the short destination address. */
	const LAddress::L2Type& getDstAddr() const
	{
		return DstAddr;
	}

	/** @brief Set method for the short destination address. */
	void setDstAddr(int addr)
	{
		DstAddr = addr;
	}

	/** @brief Get method for the number of octets contained in the MSDU. */
	const int getMsduLength() const
	{
		return msduLength;
	}

	/** @brief Set method for the number of octets contained in the MSDU. */
	void setMsduLength(int length)
	{
		msduLength = length;
	}

	/** @brief Get method for the LQI value. */
	const int getMpduLinkQuality() const
	{
		return mpduLinkQuality;
	}

	/** @brief Set method for the LQI value. */
	void setMpduLinkQuality(int value)
	{
		mpduLinkQuality = value;
	}

	/** @brief Get method for the data sequence number. */
	const int getDSN() const
	{
		return DSN;
	}

	/** @brief Set method for the data sequence number. */
	void setDSN(int number)
	{
		DSN = number;
	}

	/** @brief Get method for the timestamp. */
	const int getTimestamp() const
	{
		return Timestamp;
	}

	/** @brief Set method for the timestamp. */
	void setTimestamp(int time)
	{
		Timestamp = time;
	}

	/** @brief Get method for the security level to be used. */
	const int getSecurityLevel() const
	{
		return SecurityLevel;
	}

	/** @brief Set method for the security level to be used. */
	void setSecurityLevel(int level)
	{
		SecurityLevel = level;
	}

	/** @brief Get method for the KeyIdMode. */
	const int getKeyIdMode() const
	{
		return KeyIdMode;
	}

	/** @brief Set method for the KeyIdMode. */
	void setKeyIdMode(int mode)
	{
		KeyIdMode = mode;
	}

	/** @brief Get method for the KeySource. */
	const int getKeySource() const
	{
		return KeySource;
	}

	/** @brief Set method for the KeySource. */
	void setKeySource(int source)
	{
		KeySource = source;
	}

	/** @brief Get method for the KeyIndex. */
	const int getKeyIndex() const
	{
		return KeyIndex;
	}

	/** @brief Set method for the KeyIndex. */
	void setKeyIndex(int index)
	{
		KeyIndex = index;
	}

	/** @brief Get method for the preamble repetition value. */
	const int getUWBPreambleSymbolRepetitions() const
	{
		return UWBPreambleSymbolRepetitions;
	}

	/** @brief Set method for the preamble repetition value. */
	void setUWBPreambleSymbolRepetitions(int value)
	{
		UWBPreambleSymbolRepetitions = value;
	}

	/** @brief Get method for the data rate. */
	const int getDataRate() const
	{
		return DataRate;
	}

	/** @brief Set method for the data rate. */
	void setDataRate(int rate)
	{
		DataRate = rate;
	}

	/** @brief Get method for the start value of the ranging counter. */
	const uint getRangingCounterStart() const
	{
		return RangingCounterStart;
	}

	/** @brief Set method for the data rate. */
	void setRangingCounterStart(uint time)
	{
		RangingCounterStart = time;
	}

	/** @brief Get method for the stop value of the ranging counter. */
	const uint getRangingCounterStop() const
	{
		return RangingCounterStop;
	}

	/** @brief Set method for the stop value of the ranging counter. */
	void setRangingCounterStop(uint time)
	{
		RangingCounterStop = time;
	}

	/** @brief Get method for the tracking interval. */
	const int getRangingTrackingInterval() const
	{
		return RangingTrackingInterval;
	}

	/** @brief Set method for the ranging tracking interval. */
	void setRangingTrackingInterval(int interval)
	{
		RangingTrackingInterval = interval;
	}

	/** @brief Get method for the ranging offset value. */
	const int getRangingOffset() const
	{
		return RangingOffset;
	}

	/** @brief Set method for the ranging offset value. */
	void setRangingOffset(int value)
	{
		RangingOffset = value;
	}

	/** @brief Get method for the ranging FoM value. */
	const int getRangingFOM() const
	{
		return RangingFOM;
	}

	/** @brief Set method for the ranging FoM value. */
	void setRangingFOM(int value)
	{
		RangingFOM = value;
	}

	/** @brief Get method for the status code. */
	const status_type getStatus() const
	{
		return status;
	}

	/** @brief Set method for the status code. */
	void setStatus(status_type value)
	{
		status = value;
	}

	/**
	 *
	 * @brief Creates a network to MAC info structure and attaches it
	 *        to the passed message.
	 *
	 */
	static MacToNetwInfo * const setControlInfo(cMessage * const pMsg)
	{
		MacToNetwInfo * const pInfo = new MacToNetwInfo();

		pMsg->setControlInfo(pInfo);

		return pInfo;
	}

	/**
	 *
	 * @brief Extracts and returns the extended destination address from the
	 *        passed info structure.
	 *
	 */
	static const LAddress::L2Type& getDestFromControlInfo(const cObject * const pObject)
	{
		const MacToNetwInfo * const pInfo = dynamic_cast<const MacToNetwInfo *>(pObject);
		assert(pInfo);

		return pInfo->getDstAddr();
	}

};

#endif
