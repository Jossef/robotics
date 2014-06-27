/*
 * Manager.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "Manager.h"

Manager::Manager(Robot* robot, Plan* plan)
{
	_robot = robot;
	_plan = plan;
	_currentBehavior = plan->startBehavior();
	_running = false;
}

void Manager::run()
{
	_running = true;
	_robot->refresh();

	if (_currentBehavior->startCondition() == false)
	{
		_currentBehavior = _currentBehavior->getNextBehavior();

		// If there are no more behaviors
		if (!_currentBehavior)
		{
			return;
		}
	}

	while (_running)
	{
		_robot->refresh();
		if (_currentBehavior->stopCondition())
		{
			_currentBehavior = _currentBehavior->getNextBehavior();

			// If there are no more behaviors
			if (!_currentBehavior)
			{
				return;
			}
		}
		_currentBehavior->action();
	}

}

Manager::~Manager()
{
}
