#include "base/connectionManager/BaseConnectionManager.h"

#include "GliderPhyLayer.h"
#include "GliderAnalogueModel.h"
#include "GliderDecider.h"

Define_Module(GliderPhyLayer);

AnalogueModel* GliderPhyLayer::getAnalogueModelFromName(std::string name, ParameterMap& params)
{

	if (name == "GliderAnalogueModel")
	{
		return initializeGliderAnalogueModel(params);
	}

	return BasePhyLayer::getAnalogueModelFromName(name, params);
}

AnalogueModel* GliderPhyLayer::initializeGliderAnalogueModel(ParameterMap& params)
{

	double carrierFrequency = 8.68e+8;
	double kappa = 0;
	double zeta = 0;
	ParameterMap::iterator it;

	it = params.find("carrierFrequency"); // get parameter carrierFrequency from config.xml

	if (it != params.end()) // parameter carrierFrequency has been specified in config.xml
	{
		carrierFrequency = it->second.doubleValue(); // set carrierFrequency
		coreEV << "initializeGliderAnalogueModel(): carrierFrequency set from config.xml to " << carrierFrequency << endl;

		if (cc->hasPar("carrierFrequency") && carrierFrequency < cc->par("carrierFrequency").doubleValue()) // check whether carrierFrequency is not smaller than specified in ConnectionManager
		{
			opp_error(
					"PgPhyLayer::initializeGliderAnalogueModel(): carrierFrequency must not be smaller than specified in ConnectionManager. Please adjust your config.xml file accordingly");
		}
	}
	else // parameter carrierFrequency has not been specified in config.xml
	{
		if (cc->hasPar("carrierFrequency")) // parameter carrierFrequency has been specified in ConnectionManager
		{
			carrierFrequency = cc->par("carrierFrequency").doubleValue(); // set carrierFrequency according to ConnectionManager
			coreEV << "PgPhyLayer::initializeGliderAnalogueModel(): carrierFrequency set from ConnectionManager to " << carrierFrequency << endl;
		}
		else // parameter carrierFrequency has not been specified in ConnectionManager
		{
			coreEV << "PgPhyLayer::initializeGliderAnalogueModel(): carrierFrequency set from default value to " << carrierFrequency << endl; // keep carrierFrequency at default value
		}
	}

	it = params.find("kappa"); // get parameter kappa from config

	if (it != params.end()) // parameter kappa has been specified in config.xml
	{
		kappa = it->second.doubleValue(); // set kappa
		coreEV << "initializeGliderAnalogueModel(): kappa set from config.xml to " << kappa << endl;

		if (cc->hasPar("kappa") && kappa < cc->par("kappa").doubleValue()) // check whether kappa is not smaller than specified in ConnectionManager
		{
			opp_error(
					"PgPhyLayer::initializeGliderAnalogueModel(): kappa can't be smaller than specified in ConnectionManager. Please adjust your config.xml file accordingly");
		}
	}
	else // parameter kappa has not been specified in config.xml
	{
		if (cc->hasPar("kappa")) // parameter kappa has been specified in ConnectionManager
		{
			kappa = cc->par("kappa").doubleValue(); // set kappa according to ConnectionManager
			coreEV << "PgPhyLayer::initializeGliderAnalogueModel(): kappa set from ConnectionManager to " << kappa << endl;
		}
		else // kappa has not been specified in ConnectionManager
		{
			coreEV << "PgPhyLayer::initializeGliderAnalogueModel(): kappa set from default value to " << kappa << endl; // keep kappa at default value
		}
	}

	it = params.find("zeta"); // get parameter zeta from config

	if (it != params.end()) // parameter zeta has been specified in config.xml
	{
		zeta = it->second.doubleValue(); // set parameter zeta
		coreEV << "initializeGliderAnalogueModel(): zeta set from config.xml to " << zeta << endl;

		if (cc->hasPar("zeta") && zeta < cc->par("zeta").doubleValue()) // check whether zeta is not smaller than specified in ConnectionManager
		{
			opp_error(
					"PgPhyLayer::initializeGliderAnalogueModel(): zeta can't be smaller than specified in ConnectionManager. Please adjust your config.xml file accordingly");
		}
	}
	else // parameter zeta has not been specified in config.xml
	{
		if (cc->hasPar("zeta")) // parameter zeta has been specified in ConnectionManager
		{
			zeta = cc->par("zeta").doubleValue(); // set parameter zeta according to ConnectionManager
			coreEV << "PgPhyLayer::initializeGliderAnalogueModel(): zeta set from ConnectionManager to " << zeta << endl;
		}
		else // parameter zeta has not been specified in ConnectionManager
		{
			coreEV << "PgPhyLayer::initializeGliderAnalogueModel(): zeta set from default value to " << zeta << endl; // keep zeta at default value
		}
	}

	return new GliderAnalogueModel(carrierFrequency, kappa, zeta, coreDebug);

}

Decider* GliderPhyLayer::getDeciderFromName(std::string name, ParameterMap& params)
{
	if (name == "GliderDecider")
	{
		return new GliderDecider(this, 0.0, 0, true);
	}

	return BasePhyLayer::getDeciderFromName(name, params);
}
