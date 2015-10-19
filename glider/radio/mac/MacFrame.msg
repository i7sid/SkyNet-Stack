//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

cplusplus {{
#include "glider/radio/mac/mac_types.h"
}}

class mac_types::frame_type extends void;
class mac_types::addressing_mode extends void;
class mac_types::command_frame_identifier extends void;

//
// Message for all types of MAC frames according to IEEE 802.15.4
// 

packet MacFrame
{
    // type of the MAC frame
    mac_types::frame_type frame_type;    
    
    // keys for the frame control field
    bool securityEnabled;
    bool framePending;
    bool ackRequest;
    bool panIdCompression;
    mac_types::addressing_mode dest_addressing_mode;
    int frameVersion;
    mac_types::addressing_mode source_addressing_mode;

	// keys for the superframe specification field
	short beaconOrder;
	short superframeOrder;
	short finalCapSlot;
	bool batteryLifeExtension;
	bool panCoordinator;
	bool associationPermit;

	// key for the sequence number
	short sequenceNumber;
	    
    // keys for the addressing field
    short destPan;
    long destAddr;
    short srcPan;
    long srcAddr;
    
    // keys for the auxiliary security header
    short securityLevel;
    short keyIdentifierMode;

    // key for the checksum
    int fcs;
    
    // keys for the command frame payload
    mac_types::command_frame_identifier commandFrameIdentifier;
    
    // association request keys
    bool deviceType;
    bool powerSource;
    bool receiverOnWhenIdle;
    bool securityCapability;
    bool allocateAddress;
    
    // association response keys
    short allocatedAddress;
    short associationStatus;
}
