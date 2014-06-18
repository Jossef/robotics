/*
 * GoRight.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: user
 */

#include "GoLeft.h"

GoLeft::GoLeft(Robot *robot):Behavior(robot)
{

}

bool GoLeft::startCondition()
{
	if((_robot->getLaserDistance(555) > 0.3) && (_robot->getLaserDistance(333) > 0.3))
			return true;
		return false;
}

void GoLeft::action()
{
	_robot->setSpeed(0.0,-0.5);
}

bool GoLeft::stopCondition()
{
	return !startCondition();
}

GoLeft::~GoLeft()
{
}
