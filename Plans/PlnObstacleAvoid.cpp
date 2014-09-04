/*
 * PlnObstacleAvoid.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "PlnObstacleAvoid.h"

#include "../Behaviors/GoForward.h"
#include "../Behaviors/GoBackward.h"
#include "../Behaviors/GoRight.h"
#include "../Behaviors/GoLeft.h"

#include "../Behaviors/GoRandomDirection.h"

PlnObstacleAvoid::PlnObstacleAvoid(Robot* robot):Plan(robot)
{


	//Creating behaviors
	GoForward* goForwardBehavior = new GoForward(_robot);
	GoBackward* goBackwardBehavior = new GoBackward(_robot);
	GoRight* goRightBehavior = new GoRight(_robot);
	GoLeft* goLeftBehavior = new GoLeft(_robot);
	GoRandomDirection* goRandomDirection = new GoRandomDirection(_robot, goLeftBehavior, goRightBehavior);


	_behaviors.push_back(goForwardBehavior);
	_behaviors.push_back(goRightBehavior);
	_behaviors.push_back(goLeftBehavior);
	_behaviors.push_back(goRandomDirection);
	_behaviors.push_back(goBackwardBehavior);

	//Connecting behaviors
	// goForward
	goForwardBehavior->addNextBehavior(goRandomDirection);
	goForwardBehavior->addNextBehavior(goBackwardBehavior);

	// goRandom
	goRandomDirection->addNextBehavior(goForwardBehavior);
	goRandomDirection->addNextBehavior(goBackwardBehavior);

	// goBackward
	goBackwardBehavior->addNextBehavior(goRandomDirection);
	goBackwardBehavior->addNextBehavior(goBackwardBehavior);

	// goRight
	goRightBehavior->addNextBehavior(goForwardBehavior);

	// goLeft
	goLeftBehavior->addNextBehavior(goForwardBehavior);

	// set start behavior
	_startBehavior = goForwardBehavior;
}

Behavior* PlnObstacleAvoid::startBehavior()
{
	return _startBehavior;
}

PlnObstacleAvoid::~PlnObstacleAvoid()
{
}
