//
// Generated file, do not edit! Created by nedtool 4.6 from glider/radio/mac/MacFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MacFrame_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(MacFrame);

MacFrame::MacFrame(const char *name, int kind) : ::cPacket(name,kind)
{
    this->securityEnabled_var = 0;
    this->framePending_var = 0;
    this->ackRequest_var = 0;
    this->panIdCompression_var = 0;
    this->frameVersion_var = 0;
    this->beaconOrder_var = 0;
    this->superframeOrder_var = 0;
    this->finalCapSlot_var = 0;
    this->batteryLifeExtension_var = 0;
    this->panCoordinator_var = 0;
    this->associationPermit_var = 0;
    this->sequenceNumber_var = 0;
    this->destPan_var = 0;
    this->destAddr_var = 0;
    this->srcPan_var = 0;
    this->srcAddr_var = 0;
    this->securityLevel_var = 0;
    this->keyIdentifierMode_var = 0;
    this->fcs_var = 0;
    this->deviceType_var = 0;
    this->powerSource_var = 0;
    this->receiverOnWhenIdle_var = 0;
    this->securityCapability_var = 0;
    this->allocateAddress_var = 0;
    this->allocatedAddress_var = 0;
    this->associationStatus_var = 0;
}

MacFrame::MacFrame(const MacFrame& other) : ::cPacket(other)
{
    copy(other);
}

MacFrame::~MacFrame()
{
}

MacFrame& MacFrame::operator=(const MacFrame& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MacFrame::copy(const MacFrame& other)
{
    this->frame_type_var = other.frame_type_var;
    this->securityEnabled_var = other.securityEnabled_var;
    this->framePending_var = other.framePending_var;
    this->ackRequest_var = other.ackRequest_var;
    this->panIdCompression_var = other.panIdCompression_var;
    this->dest_addressing_mode_var = other.dest_addressing_mode_var;
    this->frameVersion_var = other.frameVersion_var;
    this->source_addressing_mode_var = other.source_addressing_mode_var;
    this->beaconOrder_var = other.beaconOrder_var;
    this->superframeOrder_var = other.superframeOrder_var;
    this->finalCapSlot_var = other.finalCapSlot_var;
    this->batteryLifeExtension_var = other.batteryLifeExtension_var;
    this->panCoordinator_var = other.panCoordinator_var;
    this->associationPermit_var = other.associationPermit_var;
    this->sequenceNumber_var = other.sequenceNumber_var;
    this->destPan_var = other.destPan_var;
    this->destAddr_var = other.destAddr_var;
    this->srcPan_var = other.srcPan_var;
    this->srcAddr_var = other.srcAddr_var;
    this->securityLevel_var = other.securityLevel_var;
    this->keyIdentifierMode_var = other.keyIdentifierMode_var;
    this->fcs_var = other.fcs_var;
    this->commandFrameIdentifier_var = other.commandFrameIdentifier_var;
    this->deviceType_var = other.deviceType_var;
    this->powerSource_var = other.powerSource_var;
    this->receiverOnWhenIdle_var = other.receiverOnWhenIdle_var;
    this->securityCapability_var = other.securityCapability_var;
    this->allocateAddress_var = other.allocateAddress_var;
    this->allocatedAddress_var = other.allocatedAddress_var;
    this->associationStatus_var = other.associationStatus_var;
}

void MacFrame::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->frame_type_var);
    doPacking(b,this->securityEnabled_var);
    doPacking(b,this->framePending_var);
    doPacking(b,this->ackRequest_var);
    doPacking(b,this->panIdCompression_var);
    doPacking(b,this->dest_addressing_mode_var);
    doPacking(b,this->frameVersion_var);
    doPacking(b,this->source_addressing_mode_var);
    doPacking(b,this->beaconOrder_var);
    doPacking(b,this->superframeOrder_var);
    doPacking(b,this->finalCapSlot_var);
    doPacking(b,this->batteryLifeExtension_var);
    doPacking(b,this->panCoordinator_var);
    doPacking(b,this->associationPermit_var);
    doPacking(b,this->sequenceNumber_var);
    doPacking(b,this->destPan_var);
    doPacking(b,this->destAddr_var);
    doPacking(b,this->srcPan_var);
    doPacking(b,this->srcAddr_var);
    doPacking(b,this->securityLevel_var);
    doPacking(b,this->keyIdentifierMode_var);
    doPacking(b,this->fcs_var);
    doPacking(b,this->commandFrameIdentifier_var);
    doPacking(b,this->deviceType_var);
    doPacking(b,this->powerSource_var);
    doPacking(b,this->receiverOnWhenIdle_var);
    doPacking(b,this->securityCapability_var);
    doPacking(b,this->allocateAddress_var);
    doPacking(b,this->allocatedAddress_var);
    doPacking(b,this->associationStatus_var);
}

void MacFrame::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->frame_type_var);
    doUnpacking(b,this->securityEnabled_var);
    doUnpacking(b,this->framePending_var);
    doUnpacking(b,this->ackRequest_var);
    doUnpacking(b,this->panIdCompression_var);
    doUnpacking(b,this->dest_addressing_mode_var);
    doUnpacking(b,this->frameVersion_var);
    doUnpacking(b,this->source_addressing_mode_var);
    doUnpacking(b,this->beaconOrder_var);
    doUnpacking(b,this->superframeOrder_var);
    doUnpacking(b,this->finalCapSlot_var);
    doUnpacking(b,this->batteryLifeExtension_var);
    doUnpacking(b,this->panCoordinator_var);
    doUnpacking(b,this->associationPermit_var);
    doUnpacking(b,this->sequenceNumber_var);
    doUnpacking(b,this->destPan_var);
    doUnpacking(b,this->destAddr_var);
    doUnpacking(b,this->srcPan_var);
    doUnpacking(b,this->srcAddr_var);
    doUnpacking(b,this->securityLevel_var);
    doUnpacking(b,this->keyIdentifierMode_var);
    doUnpacking(b,this->fcs_var);
    doUnpacking(b,this->commandFrameIdentifier_var);
    doUnpacking(b,this->deviceType_var);
    doUnpacking(b,this->powerSource_var);
    doUnpacking(b,this->receiverOnWhenIdle_var);
    doUnpacking(b,this->securityCapability_var);
    doUnpacking(b,this->allocateAddress_var);
    doUnpacking(b,this->allocatedAddress_var);
    doUnpacking(b,this->associationStatus_var);
}

frame_type& MacFrame::getFrame_type()
{
    return frame_type_var;
}

void MacFrame::setFrame_type(const frame_type& frame_type)
{
    this->frame_type_var = frame_type;
}

bool MacFrame::getSecurityEnabled() const
{
    return securityEnabled_var;
}

void MacFrame::setSecurityEnabled(bool securityEnabled)
{
    this->securityEnabled_var = securityEnabled;
}

bool MacFrame::getFramePending() const
{
    return framePending_var;
}

void MacFrame::setFramePending(bool framePending)
{
    this->framePending_var = framePending;
}

bool MacFrame::getAckRequest() const
{
    return ackRequest_var;
}

void MacFrame::setAckRequest(bool ackRequest)
{
    this->ackRequest_var = ackRequest;
}

bool MacFrame::getPanIdCompression() const
{
    return panIdCompression_var;
}

void MacFrame::setPanIdCompression(bool panIdCompression)
{
    this->panIdCompression_var = panIdCompression;
}

addressing_mode& MacFrame::getDest_addressing_mode()
{
    return dest_addressing_mode_var;
}

void MacFrame::setDest_addressing_mode(const addressing_mode& dest_addressing_mode)
{
    this->dest_addressing_mode_var = dest_addressing_mode;
}

int MacFrame::getFrameVersion() const
{
    return frameVersion_var;
}

void MacFrame::setFrameVersion(int frameVersion)
{
    this->frameVersion_var = frameVersion;
}

addressing_mode& MacFrame::getSource_addressing_mode()
{
    return source_addressing_mode_var;
}

void MacFrame::setSource_addressing_mode(const addressing_mode& source_addressing_mode)
{
    this->source_addressing_mode_var = source_addressing_mode;
}

short MacFrame::getBeaconOrder() const
{
    return beaconOrder_var;
}

void MacFrame::setBeaconOrder(short beaconOrder)
{
    this->beaconOrder_var = beaconOrder;
}

short MacFrame::getSuperframeOrder() const
{
    return superframeOrder_var;
}

void MacFrame::setSuperframeOrder(short superframeOrder)
{
    this->superframeOrder_var = superframeOrder;
}

short MacFrame::getFinalCapSlot() const
{
    return finalCapSlot_var;
}

void MacFrame::setFinalCapSlot(short finalCapSlot)
{
    this->finalCapSlot_var = finalCapSlot;
}

bool MacFrame::getBatteryLifeExtension() const
{
    return batteryLifeExtension_var;
}

void MacFrame::setBatteryLifeExtension(bool batteryLifeExtension)
{
    this->batteryLifeExtension_var = batteryLifeExtension;
}

bool MacFrame::getPanCoordinator() const
{
    return panCoordinator_var;
}

void MacFrame::setPanCoordinator(bool panCoordinator)
{
    this->panCoordinator_var = panCoordinator;
}

bool MacFrame::getAssociationPermit() const
{
    return associationPermit_var;
}

void MacFrame::setAssociationPermit(bool associationPermit)
{
    this->associationPermit_var = associationPermit;
}

short MacFrame::getSequenceNumber() const
{
    return sequenceNumber_var;
}

void MacFrame::setSequenceNumber(short sequenceNumber)
{
    this->sequenceNumber_var = sequenceNumber;
}

short MacFrame::getDestPan() const
{
    return destPan_var;
}

void MacFrame::setDestPan(short destPan)
{
    this->destPan_var = destPan;
}

long MacFrame::getDestAddr() const
{
    return destAddr_var;
}

void MacFrame::setDestAddr(long destAddr)
{
    this->destAddr_var = destAddr;
}

short MacFrame::getSrcPan() const
{
    return srcPan_var;
}

void MacFrame::setSrcPan(short srcPan)
{
    this->srcPan_var = srcPan;
}

long MacFrame::getSrcAddr() const
{
    return srcAddr_var;
}

void MacFrame::setSrcAddr(long srcAddr)
{
    this->srcAddr_var = srcAddr;
}

short MacFrame::getSecurityLevel() const
{
    return securityLevel_var;
}

void MacFrame::setSecurityLevel(short securityLevel)
{
    this->securityLevel_var = securityLevel;
}

short MacFrame::getKeyIdentifierMode() const
{
    return keyIdentifierMode_var;
}

void MacFrame::setKeyIdentifierMode(short keyIdentifierMode)
{
    this->keyIdentifierMode_var = keyIdentifierMode;
}

int MacFrame::getFcs() const
{
    return fcs_var;
}

void MacFrame::setFcs(int fcs)
{
    this->fcs_var = fcs;
}

command_frame_identifier& MacFrame::getCommandFrameIdentifier()
{
    return commandFrameIdentifier_var;
}

void MacFrame::setCommandFrameIdentifier(const command_frame_identifier& commandFrameIdentifier)
{
    this->commandFrameIdentifier_var = commandFrameIdentifier;
}

bool MacFrame::getDeviceType() const
{
    return deviceType_var;
}

void MacFrame::setDeviceType(bool deviceType)
{
    this->deviceType_var = deviceType;
}

bool MacFrame::getPowerSource() const
{
    return powerSource_var;
}

void MacFrame::setPowerSource(bool powerSource)
{
    this->powerSource_var = powerSource;
}

bool MacFrame::getReceiverOnWhenIdle() const
{
    return receiverOnWhenIdle_var;
}

void MacFrame::setReceiverOnWhenIdle(bool receiverOnWhenIdle)
{
    this->receiverOnWhenIdle_var = receiverOnWhenIdle;
}

bool MacFrame::getSecurityCapability() const
{
    return securityCapability_var;
}

void MacFrame::setSecurityCapability(bool securityCapability)
{
    this->securityCapability_var = securityCapability;
}

bool MacFrame::getAllocateAddress() const
{
    return allocateAddress_var;
}

void MacFrame::setAllocateAddress(bool allocateAddress)
{
    this->allocateAddress_var = allocateAddress;
}

short MacFrame::getAllocatedAddress() const
{
    return allocatedAddress_var;
}

void MacFrame::setAllocatedAddress(short allocatedAddress)
{
    this->allocatedAddress_var = allocatedAddress;
}

short MacFrame::getAssociationStatus() const
{
    return associationStatus_var;
}

void MacFrame::setAssociationStatus(short associationStatus)
{
    this->associationStatus_var = associationStatus;
}

class MacFrameDescriptor : public cClassDescriptor
{
  public:
    MacFrameDescriptor();
    virtual ~MacFrameDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MacFrameDescriptor);

MacFrameDescriptor::MacFrameDescriptor() : cClassDescriptor("MacFrame", "cPacket")
{
}

MacFrameDescriptor::~MacFrameDescriptor()
{
}

bool MacFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MacFrame *>(obj)!=NULL;
}

const char *MacFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MacFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 30+basedesc->getFieldCount(object) : 30;
}

unsigned int MacFrameDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<30) ? fieldTypeFlags[field] : 0;
}

const char *MacFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "frame_type",
        "securityEnabled",
        "framePending",
        "ackRequest",
        "panIdCompression",
        "dest_addressing_mode",
        "frameVersion",
        "source_addressing_mode",
        "beaconOrder",
        "superframeOrder",
        "finalCapSlot",
        "batteryLifeExtension",
        "panCoordinator",
        "associationPermit",
        "sequenceNumber",
        "destPan",
        "destAddr",
        "srcPan",
        "srcAddr",
        "securityLevel",
        "keyIdentifierMode",
        "fcs",
        "commandFrameIdentifier",
        "deviceType",
        "powerSource",
        "receiverOnWhenIdle",
        "securityCapability",
        "allocateAddress",
        "allocatedAddress",
        "associationStatus",
    };
    return (field>=0 && field<30) ? fieldNames[field] : NULL;
}

int MacFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "frame_type")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "securityEnabled")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "framePending")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackRequest")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "panIdCompression")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest_addressing_mode")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameVersion")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "source_addressing_mode")==0) return base+7;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconOrder")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "superframeOrder")==0) return base+9;
    if (fieldName[0]=='f' && strcmp(fieldName, "finalCapSlot")==0) return base+10;
    if (fieldName[0]=='b' && strcmp(fieldName, "batteryLifeExtension")==0) return base+11;
    if (fieldName[0]=='p' && strcmp(fieldName, "panCoordinator")==0) return base+12;
    if (fieldName[0]=='a' && strcmp(fieldName, "associationPermit")==0) return base+13;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+14;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPan")==0) return base+15;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+16;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPan")==0) return base+17;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+18;
    if (fieldName[0]=='s' && strcmp(fieldName, "securityLevel")==0) return base+19;
    if (fieldName[0]=='k' && strcmp(fieldName, "keyIdentifierMode")==0) return base+20;
    if (fieldName[0]=='f' && strcmp(fieldName, "fcs")==0) return base+21;
    if (fieldName[0]=='c' && strcmp(fieldName, "commandFrameIdentifier")==0) return base+22;
    if (fieldName[0]=='d' && strcmp(fieldName, "deviceType")==0) return base+23;
    if (fieldName[0]=='p' && strcmp(fieldName, "powerSource")==0) return base+24;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiverOnWhenIdle")==0) return base+25;
    if (fieldName[0]=='s' && strcmp(fieldName, "securityCapability")==0) return base+26;
    if (fieldName[0]=='a' && strcmp(fieldName, "allocateAddress")==0) return base+27;
    if (fieldName[0]=='a' && strcmp(fieldName, "allocatedAddress")==0) return base+28;
    if (fieldName[0]=='a' && strcmp(fieldName, "associationStatus")==0) return base+29;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MacFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "mac_types::frame_type",
        "bool",
        "bool",
        "bool",
        "bool",
        "mac_types::addressing_mode",
        "int",
        "mac_types::addressing_mode",
        "short",
        "short",
        "short",
        "bool",
        "bool",
        "bool",
        "short",
        "short",
        "long",
        "short",
        "long",
        "short",
        "short",
        "int",
        "mac_types::command_frame_identifier",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "short",
        "short",
    };
    return (field>=0 && field<30) ? fieldTypeStrings[field] : NULL;
}

const char *MacFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MacFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MacFrame *pp = (MacFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MacFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MacFrame *pp = (MacFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getFrame_type(); return out.str();}
        case 1: return bool2string(pp->getSecurityEnabled());
        case 2: return bool2string(pp->getFramePending());
        case 3: return bool2string(pp->getAckRequest());
        case 4: return bool2string(pp->getPanIdCompression());
        case 5: {std::stringstream out; out << pp->getDest_addressing_mode(); return out.str();}
        case 6: return long2string(pp->getFrameVersion());
        case 7: {std::stringstream out; out << pp->getSource_addressing_mode(); return out.str();}
        case 8: return long2string(pp->getBeaconOrder());
        case 9: return long2string(pp->getSuperframeOrder());
        case 10: return long2string(pp->getFinalCapSlot());
        case 11: return bool2string(pp->getBatteryLifeExtension());
        case 12: return bool2string(pp->getPanCoordinator());
        case 13: return bool2string(pp->getAssociationPermit());
        case 14: return long2string(pp->getSequenceNumber());
        case 15: return long2string(pp->getDestPan());
        case 16: return long2string(pp->getDestAddr());
        case 17: return long2string(pp->getSrcPan());
        case 18: return long2string(pp->getSrcAddr());
        case 19: return long2string(pp->getSecurityLevel());
        case 20: return long2string(pp->getKeyIdentifierMode());
        case 21: return long2string(pp->getFcs());
        case 22: {std::stringstream out; out << pp->getCommandFrameIdentifier(); return out.str();}
        case 23: return bool2string(pp->getDeviceType());
        case 24: return bool2string(pp->getPowerSource());
        case 25: return bool2string(pp->getReceiverOnWhenIdle());
        case 26: return bool2string(pp->getSecurityCapability());
        case 27: return bool2string(pp->getAllocateAddress());
        case 28: return long2string(pp->getAllocatedAddress());
        case 29: return long2string(pp->getAssociationStatus());
        default: return "";
    }
}

bool MacFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MacFrame *pp = (MacFrame *)object; (void)pp;
    switch (field) {
        case 1: pp->setSecurityEnabled(string2bool(value)); return true;
        case 2: pp->setFramePending(string2bool(value)); return true;
        case 3: pp->setAckRequest(string2bool(value)); return true;
        case 4: pp->setPanIdCompression(string2bool(value)); return true;
        case 6: pp->setFrameVersion(string2long(value)); return true;
        case 8: pp->setBeaconOrder(string2long(value)); return true;
        case 9: pp->setSuperframeOrder(string2long(value)); return true;
        case 10: pp->setFinalCapSlot(string2long(value)); return true;
        case 11: pp->setBatteryLifeExtension(string2bool(value)); return true;
        case 12: pp->setPanCoordinator(string2bool(value)); return true;
        case 13: pp->setAssociationPermit(string2bool(value)); return true;
        case 14: pp->setSequenceNumber(string2long(value)); return true;
        case 15: pp->setDestPan(string2long(value)); return true;
        case 16: pp->setDestAddr(string2long(value)); return true;
        case 17: pp->setSrcPan(string2long(value)); return true;
        case 18: pp->setSrcAddr(string2long(value)); return true;
        case 19: pp->setSecurityLevel(string2long(value)); return true;
        case 20: pp->setKeyIdentifierMode(string2long(value)); return true;
        case 21: pp->setFcs(string2long(value)); return true;
        case 23: pp->setDeviceType(string2bool(value)); return true;
        case 24: pp->setPowerSource(string2bool(value)); return true;
        case 25: pp->setReceiverOnWhenIdle(string2bool(value)); return true;
        case 26: pp->setSecurityCapability(string2bool(value)); return true;
        case 27: pp->setAllocateAddress(string2bool(value)); return true;
        case 28: pp->setAllocatedAddress(string2long(value)); return true;
        case 29: pp->setAssociationStatus(string2long(value)); return true;
        default: return false;
    }
}

const char *MacFrameDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return opp_typename(typeid(frame_type));
        case 5: return opp_typename(typeid(addressing_mode));
        case 7: return opp_typename(typeid(addressing_mode));
        case 22: return opp_typename(typeid(command_frame_identifier));
        default: return NULL;
    };
}

void *MacFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MacFrame *pp = (MacFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getFrame_type()); break;
        case 5: return (void *)(&pp->getDest_addressing_mode()); break;
        case 7: return (void *)(&pp->getSource_addressing_mode()); break;
        case 22: return (void *)(&pp->getCommandFrameIdentifier()); break;
        default: return NULL;
    }
}


