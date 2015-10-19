package skynet.glider.radio;

import skynet.glider.radio.phy.GliderPhyLayer;
import skynet.glider.radio.mac.GliderMacLayer;

//
// This NIC implements an 802.15.4 network interface card.
//

module GliderNic
{
    gates:
        input upperLayerIn;
        output upperLayerOut;
        input upperControlIn;
        output upperControlOut;
        input radioIn;

    submodules:
        phy: GliderPhyLayer {
            @display("p=70,220");
        }

        mac: GliderMacLayer {
            @display("p=70,80");
        }

    connections:
        upperLayerIn --> mac.upperLayerIn;
        upperLayerOut <-- mac.upperLayerOut;
        upperControlIn --> mac.upperControlIn;
        upperControlOut <-- mac.upperControlOut;

        mac.lowerLayerOut --> phy.upperLayerIn;
        mac.lowerLayerIn <-- phy.upperLayerOut;
        mac.lowerControlOut --> phy.upperControlIn;
        mac.lowerControlIn <-- phy.upperControlOut;

        phy.radioIn <-- radioIn;
                
}
