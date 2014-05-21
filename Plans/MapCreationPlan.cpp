/*
 * MapCreationPlan.cpp
 *
 *  Created on: May 3, 2014
 *      Author: user
 */

#include "MapCreationPlan.h"

MapCreationPlan::MapCreationPlan(Robot* robot):Plan(robot)
{
		// TODO Auto-generated constructor stub

		//Creating behaviors
		Behavior* goForwardBehavior = new GoForward(_robot);
		Behavior* goRightBehavior = new GoRight(_robot);
		Behavior* goLeftBehavior = new GoLeft(_robot);

		_behaviors.push_back(goForwardBehavior);
		_behaviors.push_back(goRightBehavior);
		_behaviors.push_back(goLeftBehavior);

		//Connecting behaviors
		goForwardBehavior->addNextBehavior(goRightBehavior);
		goForwardBehavior->addNextBehavior(goLeftBehavior);

		goRightBehavior->addNextBehavior(goForwardBehavior);
		goRightBehavior->addNextBehavior(goForwardBehavior);
		goLeftBehavior->addNextBehavior(goRightBehavior);

		_startBehavior = goForwardBehavior;
}

MapCreationPlan::~MapCreationPlan()
{

}

Behavior* MapCreationPlan::startBehavior()
{
	return _startBehavior;
}
