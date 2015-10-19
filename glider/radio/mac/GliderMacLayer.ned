package skynet.glider.radio.mac;

import skynet.base.modules.BaseMacLayer;

simple GliderMacLayer extends BaseMacLayer
{
    parameters:
        @class(GliderMacLayer);
         // debug switch
        bool debug = default(false);
        bool stats = default(true);
        bool trace = default(false);
        // length of MAC header
        headerLength @unit(bit) = default(72 bit);
        // bit rate 
        double bitrate @unit(bps) = default(250000 bps);
        //tx power [mW]
        double txPower @unit(mW);
        // # of backoff periods of the initial contention window
        // (for linear and constant backoff method only)
        int contentionWindow = default(2);
}
