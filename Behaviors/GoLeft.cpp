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
	if(_robot->getLaserDistance(555) > 0.3)
			return true;
		return false;
}

void GoLeft::action()
{
	if(_robot->getLaserDistance(555) > 3.0)
			_robot->setSpeed(1.0,0.5);
		else
			_robot->setSpeed(0.5,0.5);
}

bool GoLeft::stopCondition()
{
	if(_robot->getLaserDistance(555) < 0.3)
			return true;
		return false;
}

GoLeft::~GoLeft()
{
}
