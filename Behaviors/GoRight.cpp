/*
 * GoRight.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: user
 */


#include "GoRight.h"
#include "../Configuration.h"

GoRight::GoRight(Robot *robot):Behavior(robot)
{

}

bool GoRight::startCondition()
{
	bool startCondition = ((_robot->getLaserDistance(333) > 0.8)&& (_robot->getLaserDistance(111) > 0.8));
	return startCondition;
}

void GoRight::action()
{
	_robot->setSpeed(0.0,0.5);
}

bool GoRight::stopCondition()
{
	return !startCondition();
}



GoRight::~GoRight()
{
}





