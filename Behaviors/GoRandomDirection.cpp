/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "GoRandomDirection.h"
#include <time.h>       /* time */

GoRandomDirection::GoRandomDirection(Robot* robot) : Behavior(robot), _goLeft(robot), _goRight(robot)
{

}

bool GoRandomDirection::startCondition()
{
	return _goLeft.startCondition() && _goRight.startCondition();
}

void GoRandomDirection::action()
{
	int minutes = (time(NULL) / 60);

	if (minutes % 2 == 0)
	{
		_goLeft.action();
		return;
	}

	_goRight.action();
}

bool GoRandomDirection::stopCondition()
{
	return _goLeft.stopCondition() || _goRight.stopCondition();
}

GoRandomDirection::~GoRandomDirection()
{
}
