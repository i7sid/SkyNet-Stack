#ifndef GLIDER_APPL_LAYER_H
#define GLIDER_APPL_LAYER_H

#include "base/utils/MiXiMDefs.h"
#include "base/modules/BaseApplLayer.h"

#define applEV debugEV<<"[APPL] "

class MIXIM_API GliderApplLayer : public BaseApplLayer
{
    public:
        GliderApplLayer()
        {}

        virtual ~GliderApplLayer()
        {}

        /** @brief Initialize module parameters*/
        virtual void initialize(int);

        /** @brief Message kinds used by this layer.*/
        enum TestApplMessageKinds {
            SEND_BROADCAST_TIMER = LAST_BASE_APPL_MESSAGE_KIND,
            BROADCAST_MESSAGE,
            BROADCAST_REPLY_MESSAGE,
            LAST_TEST_APPL_MESSAGE_KIND
        };

    protected:
        /** @brief Timer message for scheduling next message.*/
        cMessage *txTimer;

        /** @brief Handle self messages such as timer. */
        virtual void handleSelfMsg(cMessage*);

        /** @brief Handle messages from lower layer. */
        virtual void handleLowerMsg(cMessage*);

        /** @brief Handle control messages from lower layer. */
        virtual void handleLowerControl(cMessage*);

        /** @brief send a broadcast packet to all connected neighbors. */
        void sendBroadcast(const char* name, double txPower_mW);

        void finish();
};

#endif

