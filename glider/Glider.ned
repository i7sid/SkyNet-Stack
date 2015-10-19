package skynet.glider;

import skynet.glider.mobility.GliderMobility;
import skynet.glider.application.GliderApplLayer;
import skynet.glider.radio.GliderNic;


module Glider
{
    parameters:
        string mobilityType = default("GliderMobility");
        @display("bgb=210,450");
        @node();

    gates:
        input radioIn;

    submodules:
        mobility: GliderMobility {
            parameters:
                @display("p=40,40");
        }
        appl: GliderApplLayer {
            parameters:
                @display("p=110,140");
        }
        nic: GliderNic {
            parameters:
                @display("p=110,340");
        }

    connections:
        appl.lowerLayerOut --> nic.upperLayerIn;
        appl.lowerLayerIn <-- nic.upperLayerOut;
        appl.lowerControlOut --> nic.upperControlIn;
        appl.lowerControlIn <-- nic.upperControlOut;
        nic.radioIn <-- radioIn;
}
