#include <base/utils/FWMath.h>
#include <cmath>
#include <math.h>

#include "base/messages/AirFrame_m.h"

#include "GliderPhyLayer.h"
#include "GliderAnalogueModel.h"
#include "glider/mobility/Position.h"
#include "glider/mobility/GliderMobility.h"

#define modelEV (ev.isDisabled()||!debug) ? ev : ev << "[PhyLayer(AnalogueModel)] "

double deg2rad(double deg)
{

	return (deg * PI / 180);

}

double rad2deg(double rad)
{

	return (rad * 180 / PI);

}

double magneticBearing(Coord from, Coord to)
{

	Coord diffC(to - from);
	double bearing = rad2deg(atan2(diffC.y, diffC.x));

	if (bearing < 0)
		bearing = bearing + 360;
	if (bearing > 360)
		bearing = bearing - 360;

	return 360 - bearing;

}

double relativSymBearing(double magneticBearing, double heading)
{

	double diff = abs(heading - magneticBearing) % 360;
	if (diff > 180)
		return (360 - diff);
	else
		return (diff);

}

void GliderAnalogueModel::filterSignal(AirFrame *frame, const Coord& senderPos, const Coord& receiverPos)
{

	Signal& sig = frame->getSignal();

	GliderMobility *gMobTx = (GliderMobility *) (dynamic_cast<GliderPhyLayer*>(sig.getSendingModule()))->getParentModule()->getParentModule()->getSubmodule("mobility");
	if (gMobTx == NULL)
	{
		modelEV << "Sender mobility not found" << endl;
		ASSERT(false);
	}

	GliderMobility *gMobRx = (GliderMobility *) (dynamic_cast<GliderPhyLayer*>(sig.getReceptionModule()))->getParentModule()->getParentModule()->getSubmodule("mobility");
	if (gMobRx == NULL)
	{
		modelEV << "Receiver mobility not found" << endl;
		ASSERT(false);
	}

	const Coord senderPos2D(senderPos.x, senderPos.y);
	const Coord receiverPos2D(receiverPos.x, receiverPos.y);
	double horDist = senderPos2D.distance(receiverPos2D);
	double deltaZ = abs(senderPos.z - receiverPos.z);

	double dist = senderPos.distance(receiverPos);
	double alpha = relativSymBearing(magneticBearing(senderPos, receiverPos), gMobTx->getCourse())
			+ relativSymBearing(magneticBearing(receiverPos, senderPos), gMobRx->getCourse());
	double beta = atan(deltaZ / horDist) * 180 / PI;

	modelEV << "Sender position [(x,y,z),dir] = [" << senderPos << "," << gMobTx->getCourse() << "]" << endl;
	modelEV << "Receiver position [(x,y,z),dir] = [" << receiverPos << "," << gMobRx->getCourse() << "]" << endl;

	double lambda = BaseWorldUtility::speedOfLight / carrierFrequency;
	double lossFreeSpace = 20 * log10(4 * PI * dist / lambda);
	double lossHor = -kappa * alpha;
	double lossVert = -zeta * beta;

	double attenuation = lossFreeSpace + lossHor + lossVert;
	modelEV << attenuation << "dB attenuation through a distance of " << dist << "m."<< endl;

	sig.addAttenuation(new GliderAnalogueModel::Mapping(attenuation, debug));

}

DimensionSet GliderAnalogueModel::Mapping::dimensions(DimensionSet::timeDomain);

double GliderAnalogueModel::Mapping::getValue(const Argument& pos) const
{

	return 1 / FWMath::dBm2mW(attenuation);

}

