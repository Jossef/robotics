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
#include "../Behaviors/GoBackward.h"

PlnObstacleAvoid::PlnObstacleAvoid(Robot* robot):Plan(robot) {
	// TODO Auto-generated constructor stub

	//Creating behaviors
	Behavior* goForwardBehavior = new GoForward(_robot);
	Behavior* goRightBehavior = new GoRight(_robot);
	Behavior* goLeftBehavior = new GoLeft(_robot);
	Behavior* goBackBehavior = new GoBackward(_robot);

	_behaviors.push_back(goForwardBehavior);
	_behaviors.push_back(goRightBehavior);
	_behaviors.push_back(goLeftBehavior);
	_behaviors.push_back(goBackBehavior);

	//Connecting behaviors
	goForwardBehavior->addNextBehavior(goRightBehavior);
	goForwardBehavior->addNextBehavior(goLeftBehavior);

	goRightBehavior->addNextBehavior(goForwardBehavior);
	goRightBehavior->addNextBehavior(goBackBehavior);
	goLeftBehavior->addNextBehavior(goForwardBehavior);
	goLeftBehavior->addNextBehavior(goBackBehavior);

	_startBehavior = goForwardBehavior;
}

Behavior* PlnObstacleAvoid::startBehavior()
{
	return _startBehavior;
}

PlnObstacleAvoid::~PlnObstacleAvoid() {
	// TODO Auto-generated destructor stub
}
