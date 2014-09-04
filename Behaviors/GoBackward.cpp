/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "GoBackward.h"

GoBackward::GoBackward(Robot* robot):Behavior(robot), _steps_count(0)
{
}

bool GoBackward::startCondition()
{
	return true;
}

void GoBackward::action()
{
	++_steps_count;
	_robot->setSpeed(-0.1,0.0);
}

bool GoBackward::stopCondition()
{
	if (_steps_count < 10)
	{
		return false;
	}
	else
	{
		_steps_count = 0;
		_robot->setSpeed(0.0, 0.0);
		return true;
	}

}

GoBackward::~GoBackward()
{
}
