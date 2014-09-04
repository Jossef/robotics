/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "GoRandomDirection.h"
#include <time.h>       /* time */

GoRandomDirection::GoRandomDirection(Robot* robot, GoLeft*	goLeft, GoRight* goRight) :
													Behavior(robot),
													_goLeft(goLeft),
													_goRight(goRight),
													_cur_behavior(NULL),
													_keep_moving(false)
{

}

bool GoRandomDirection::startCondition()
{
	return _goLeft->startCondition() && _goRight->startCondition();
}

void GoRandomDirection::action()
{
	if (!_keep_moving)
	{
		double right_rank = _robot->get_right_rank();
		double left_rank = _robot->get_left_rank();

		if (right_rank * 2 < left_rank)
		{
			_cur_behavior = _goLeft;
		}
		else if (left_rank * 2 < right_rank)
		{
			_cur_behavior = _goRight;
		}
		else
		{
			int minutes = (time(NULL) / 60);

			if (minutes % 2 == 0)
			{
				_cur_behavior = _goLeft;
			}
			else
			{
				_cur_behavior = _goRight;
			}
		}
	}

	_keep_moving = true;
	_cur_behavior->action();
}

bool GoRandomDirection::stopCondition()
{
	bool ret = _goLeft->stopCondition() || _goRight->stopCondition();// || _robot->canMoveForward();

	if (ret)
	{
		_keep_moving = false;
	}

	return ret;
}

GoRandomDirection::~GoRandomDirection()
{
}
