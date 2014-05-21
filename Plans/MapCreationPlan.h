/*
 * MapCreationPlan.h
 *
 *  Created on: May 3, 2014
 *      Author: user
 */

#ifndef MAPCREATIONPLAN_H_
#define MAPCREATIONPLAN_H_

#include "Plan.h"

#include "../Behaviors/GoForward.h"
#include "../Behaviors/GoRight.h"
#include "../Behaviors/GoLeft.h"

class MapCreationPlan : public Plan
{
public:
	virtual ~MapCreationPlan();
	MapCreationPlan(Robot* robot);
	Behavior* startBehavior();
};

#endif /* MAPCREATIONPLAN_H_ */
