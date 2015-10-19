#ifndef GLIDERDECIDER_H
#define GLIDERDECIDER_H

#include "base/phyLayer/BaseDecider.h"
#include "GliderPhyLayer.h"

class GliderDecider: public BaseDecider
{

public:

	GliderDecider(GliderPhyLayer* phy, double sensitivity, int myIndex, bool debug) :
			BaseDecider(phy, sensitivity, myIndex, debug)
	{
	}

	virtual ~GliderDecider()
	{
	}

};

#endif
