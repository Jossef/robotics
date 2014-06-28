/*
 * PlnObstacleAvoid.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "PlnObstacleAvoid.h"

#include "../Behaviors/GoForward.h"
#include "../Behaviors/GoRight.h"
#include "../Behaviors/GoLeft.h"
#include "../Behaviors/GoRandomDirection.h".h"

PlnObstacleAvoid::PlnObstacleAvoid(Robot* robot):Plan(robot) {
	// TODO Auto-generated constructor stub

	//Creating behaviors
	Behavior* goForwardBehavior = new GoForward(_robot);
	Behavior* goRightBehavior = new GoRight(_robot);
	Behavior* goLeftBehavior = new GoLeft(_robot);
	Behavior* goRandomDirection = new GoRandomDirection(_robot);

	_behaviors.push_back(goForwardBehavior);
	_behaviors.push_back(goRightBehavior);
	_behaviors.push_back(goLeftBehavior);
	_behaviors.push_back(goRandomDirection);

	//Connecting behaviors
	goForwardBehavior->addNextBehavior(goRandomDirection);

	goRandomDirection->addNextBehavior(goRightBehavior);
	goRandomDirection->addNextBehavior(goLeftBehavior);

	goRightBehavior->addNextBehavior(goForwardBehavior);
	goLeftBehavior->addNextBehavior(goForwardBehavior);

	_startBehavior = goForwardBehavior;
}

Behavior* PlnObstacleAvoid::startBehavior()
{
	return _startBehavior;
}

PlnObstacleAvoid::~PlnObstacleAvoid() {
	// TODO Auto-generated destructor stub
}
