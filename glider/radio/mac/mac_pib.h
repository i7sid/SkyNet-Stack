#ifndef MAC_PIB_H
#define MAC_PIB_H

const uint8_t aMaxPHYPacketSize = 127;
const uint8_t aTurnaroundTime = 12;

uint8_t phySymbolsPerOctet = 8;
uint8_t phySHRDuration = 32;
uint8_t phyMaxFrameDuration = phySHRDuration + ((aMaxPHYPacketSize + 1) * phySymbolsPerOctet);
uint8_t phyCCADuration = 0;

const uint8_t aBaseSlotDuration = 60;
const uint16_t aBaseSuperframeDuration = 960;
const uint8_t aGTSDescPersistenceTime = 4;
const uint8_t aMaxBeaconOverhead = 75;
const uint8_t aMaxBeaconPayloadLength = aMaxPHYPacketSize - aMaxBeaconOverhead;
const uint8_t aMaxLostBeacons = 4;
const uint8_t aMaxMPDUUnsecuredOverhead = 25;
const uint8_t aMinMPDUOverhead = 9;
const uint8_t aMaxMACSafePayloadSize = aMaxPHYPacketSize - aMaxMPDUUnsecuredOverhead;
const uint8_t aMaxMACPayloadSize = aMaxPHYPacketSize - aMinMPDUOverhead;
const uint8_t aMaxSIFSFrameSize = 18;
const uint16_t aMinCAPLength = 440;
const uint8_t aNumSuperframeSlots = 16;
const uint8_t aUnitBackoffPeriod = 20;

uint64_t macExtendedAddress;
uint32_t macAckWaitDuration = aUnitBackoffPeriod + aTurnaroundTime + phySHRDuration + (6 * phySymbolsPerOctet);
bool macAssociatedPANCoord = false;
bool MacAssociationPermit = false;
bool macAutoRequest = true;
bool macBattLifeExt = false;
uint32_t macBattLifeExtPeriods;
char macBeaconPayload[] = {};
uint32_t macBeaconPayloadLength = 0;
uint32_t macBeaconOrder = 15;
uint32_t macBeaconTxTime = 0x000000;
uint32_t macBSN = 0;
uint64_t macCoordExtendedAddress = 0;
uint32_t macCoordShortAddress = 0xffff;
uint32_t macDSN = 0;
bool macGTSPermit = false;
uint32_t macMaxBE = 5;
uint32_t macMaxCSMABackoffs = 4;
uint32_t macMaxFrameTotalWaitTime = 26 * aUnitBackoffPeriod + phyMaxFrameDuration;
uint32_t macMaxFrameRetries = 3;
uint32_t macMinBE = 3;
uint32_t macLIFSPeriod = 40;
uint32_t macSIFSPeriod = 12;
uint32_t macPANId = 0xffff;
bool macPromiscuousMode = false;
bool macRangingSupported = false;
uint32_t macResponseWaitTime = 32;
bool macRxOnWhenIdle = true;
bool macSecurityEnabled = false;
uint32_t macShortAddress = 0xffff;
uint32_t macSuperframeOrder = 15;
uint32_t macSyncSymbolOffset;
bool macTimestampSupported = false;
uint32_t macTransactionPersistenceTime = 0x01f4;
uint32_t macTxControlActiveDuration = 10000;
uint32_t macTxControlPauseDuration = 10000;
uint32_t macTxTotalDuration = 0;

#endif
