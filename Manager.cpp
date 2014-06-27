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
}
void Manager::run()
{
	_robot->refresh();

	if(_currentBehavior->startCondition() == false)
	{
		return;
	}

	_currentBehavior->action();

	while(true)
	{
		_robot->refresh();

		if(_currentBehavior->stopCondition())
		{
			_currentBehavior = _currentBehavior->getNextBehavior();

			// If there are no more behaviors
			if(!_currentBehavior_currentBehavior)
			{
				break;
			}
		}


		_currentBehavior->action();
	}

}

Manager::~Manager() {
}
