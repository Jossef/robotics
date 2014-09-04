/*
 * GoRight.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: user
 */

#include "GoRight.h"
#include "../Configuration.h"

GoRight::GoRight(Robot *robot) :
	Behavior(robot)
{

}

bool GoRight::startCondition()
{
	return _robot->canRotate();
}

void GoRight::action()
{
	_robot->setSpeed(0.0, 0.5);
}

bool GoRight::stopCondition()
{
	bool result = _robot->canMoveForward() || !_robot->canRotate();

	if (result)
	{
		_robot->setSpeed(0.0, 0.0);
	}

	return result;
}

GoRight::~GoRight()
{
}

