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
	return (_robot->canRotate());
}

void GoLeft::action()
{
	_robot->setSpeed(0.0,-0.5);
}

bool GoLeft::stopCondition()
{
	bool result = _robot->canMoveForward() || !_robot->canRotate();

	if (result)
	{
		_robot->setSpeed(0.0, 0.0);
	}

	return result;
}

GoLeft::~GoLeft()
{
}
