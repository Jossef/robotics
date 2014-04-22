/*
 * GoRight.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: user
 */


#include "GoRight.h"

GoRight::GoRight(Robot *robot):Behavior(robot)
{

}

bool GoRight::startCondition()
{
	if(_robot->getLaserDistance(333) > 0.8)
			return true;
		return false;
}

void GoRight::action()
{
	if(_robot->getLaserDistance(333) > 3.0)
			_robot->setSpeed(1.0,0.5);
		else
			_robot->setSpeed(0.5,0.5);
}

bool GoRight::stopCondition()
{
	if(_robot->getLaserDistance(333) < 0.8)
			return true;
		return false;
}



GoRight::~GoRight()
{
}





