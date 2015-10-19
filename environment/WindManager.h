/*
 * WindManager.h
 *
 *  Created on: Jul 31, 2014
 *      Author: eckert
 */

#ifndef WINDMANAGER_H_
#define WINDMANAGER_H_

#include "base/utils/MiXiMDefs.h"
#include "base/modules/BaseModule.h"
#include "base/utils/Coord.h"

class MIXIM_API WindManager: public BaseModule
{
private:

        double windDirection;
        double windSpeed;

        double windDirChange;
        double windSpeedChange;

protected:

	void initialize(int stage);

public:

	WindManager();
	virtual ~WindManager();

	Coord getWind(Coord pos);

};


#endif /* WINDMANAGER_H_ */
