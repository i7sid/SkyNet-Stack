#ifndef GLIDERPHYLAYER_H
#define GLIDERPHYLAYER_H

#include "base/utils/MiXiMDefs.h"
#include "base/phyLayer/BasePhyLayer.h"

class MIXIM_API GliderPhyLayer: public BasePhyLayer
{
protected:

	/**
	 * @brief Creates and returns an instance of the AnalogueModel with the
	 * specified name.
	 *
	 * Is able to initialize the following AnalogueModels:
	 * - PgAnalogueModel
	 */
	AnalogueModel* getAnalogueModelFromName(std::string name, ParameterMap& params);

	AnalogueModel* initializeGliderAnalogueModel(ParameterMap& params);

	/**
	 * @brief Creates and returns an instance of the decider with the specified
	 *        name.
	 *
	 * Is able to initialize directly the following decider:
	 * - PgDecider
	 */
	Decider* getDeciderFromName(std::string name, ParameterMap& params);

	void initializeGliderDecider(cXMLElement* xmlConfig);

};

#endif
