#ifndef NETWTOMACINFO_H
#define NETWTOMACINFO_H

#include <omnetpp.h>

#include "base/utils/MiXiMDefs.h"
#include "base/utils/SimpleAddress.h"
#include "mac_types.h"

/**
 *
 * @brief Structure to pass parameters from the network to the MAC layer.
 *
 **/
class MIXIM_API NetwToMacInfo: public cObject
{

protected:

	/** @brief Request type of the attached message. */
	primitive_type requestType;
	/** @brief Power for the transmisson of the MPDU. */
	double txPower;

	/** @brief Source addressing mode for this MPDU. */
	addressing_mode SrcAddrMode;
	/** @brief Destination addressing mode for this MPDU. */
	addressing_mode DstAddrMode;
	/** @brief PAN identifier of the destination device. */
	int DstPANId;
	/** @brief Address of the destination device. */
	LAddress::L2Type DstAddr;
	/** @brief Number of octets contained in the MSDU. */
	int msduLength;
	/** @brief TRUE if acknowledged transmission is used. */
	bool AckTX;
	/** @brief TRUE if a GTS is to be used for transmission. */
	bool GTSTX;
	/** @brief TRUE if indirect transmission is to be used. */
	bool IndirectTX;
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

public:

	/** @brief Default constructor. */
	NetwToMacInfo() : cObject()
			, requestType(DATA_REQUEST)
			, SrcAddrMode(EXTENDED_ADDRESS)
			, DstAddrMode(EXTENDED_ADDRESS)
			, DstPANId(0)
			, DstAddr(LAddress::L2NULL)
			, msduLength(0)
			, AckTX(false)
			, GTSTX(false)
			, IndirectTX(false)
			, SecurityLevel(0)
			, KeyIdMode(0)
			, KeySource(0)
			, KeyIndex(0)
			, UWBPreambleSymbolRepetitions(0)
			, DataRate(0)
	{};

	/** @brief Destructor. */
	~NetwToMacInfo()
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

	/** @brief Get method for the transmission power. */
	const double getTxPower() const
	{
		return txPower;
	}

	/** @brief Set method for the transmission power. */
	void setTxPower(double power)
	{
		txPower = power;
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

	/** @brief Get method for the destination address. */
	const LAddress::L2Type& getDstAddr() const
	{
		return DstAddr;
	}

	/** @brief Set method for the destination address. */
	void setDstAddr(LAddress::L2Type addr)
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

	/** @brief Get method for the AckTX flag. */
	const int getAckTX() const
	{
		return AckTX;
	}

	/** @brief Set method for the AckTX flag. */
	void setAckTX(bool flag)
	{
		AckTX = flag;
	}

	/** @brief Get method for the GTSTX flag. */
	const int getGTSTX() const
	{
		return GTSTX;
	}

	/** @brief Set method for the GTSTX flag. */
	void setGTSTX(bool flag)
	{
		GTSTX = flag;
	}

	/** @brief Set method for the IndirectTX flag. */
	const bool getIndirectTX(bool flag) const
	{
		return IndirectTX;
	}

	/** @brief Set method for the IndirectTX flag. */
	void setIndirectTX(bool flag)
	{
		IndirectTX = flag;
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

	/**
	 *
	 * @brief Creates an info structure for the passed network message with
	 *        the extended destination address and the request type.
	 *
	 */
	static cObject * const setControlInfo(cMessage * const pMsg, const LAddress::L2Type& pDestAddr)
	{
		NetwToMacInfo * const pInfo = new NetwToMacInfo();

		pInfo->setDstAddr(pDestAddr);

		pMsg->setControlInfo(pInfo);

		return pInfo;
	}

	/**
	 *
	 * @brief Extracts and returns the extended destination address from the
	 *        passed info structure.
	 *
	 */
	static const LAddress::L2Type& getDestinationFromInfo(const cObject * const pObject)
	{
		const NetwToMacInfo * const pInfo = dynamic_cast<const NetwToMacInfo *>(pObject);
		assert(pInfo);

		return pInfo->getDstAddr();
	}

	/**
	 *
	 * @brief Extracts and returns the primitive type of the message from the
	 *        passed info structure.
	 *
	 */
	static const primitive_type& getPrimitiveFromInfo(const cObject * const pObject)
	{
		const NetwToMacInfo * const pInfo = dynamic_cast<const NetwToMacInfo *>(pObject);
		assert(pInfo);

		return pInfo->getRequestType();
	}

};

#endif
