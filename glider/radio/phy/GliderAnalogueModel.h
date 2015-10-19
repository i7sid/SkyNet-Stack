#ifndef GLIDERANALOGUEMODEL_H
#define GLIDERANALOGUEMODEL_H

#include <random>

#include "base/modules/BaseWorldUtility.h"
#include "base/phyLayer/AnalogueModel.h"
#include "base/phyLayer/MappingBase.h"

class GliderAnalogueModel: public AnalogueModel
{

public:

	GliderAnalogueModel(double carrierFrequency, double kappa, double zeta, bool debug) :
			carrierFrequency(carrierFrequency), kappa(kappa), zeta(zeta), debug(debug)
	{
	}

	virtual ~GliderAnalogueModel()
	{
	}

	virtual void filterSignal(AirFrame *frame, const Coord& sendersPos, const Coord& receiverPos);

protected:

	double carrierFrequency;
	double kappa;
	double zeta;

	bool debug;

	class Mapping: public SimpleConstMapping
	{

	protected:

		static DimensionSet dimensions;

		double attenuation;
		bool debug;

	public:

		Mapping(double attenuation, bool debug) :
				SimpleConstMapping(dimensions), attenuation(attenuation), debug(debug)
		{
		}

		virtual double getValue(const Argument& pos) const;

		ConstMapping* constClone() const
		{
			return new Mapping(*this);
		}

	};

};

#endif
