/*
 * PlnObstacleAvoid.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef PLNOBSTACLEAVOID_H_
#define PLNOBSTACLEAVOID_H_

#include "Plan.h"
#include "../Behaviors/GoForward.h"
#include "../Behaviors/GoRight.h"
#include "../Behaviors/GoLeft.h"
class PlnObstacleAvoid: public Plan
{
public:
	PlnObstacleAvoid(Robot* robot);
	Behavior* startBehavior();
	virtual ~PlnObstacleAvoid();
};

#endif /* PLNOBSTACLEAVOID_H_ */
