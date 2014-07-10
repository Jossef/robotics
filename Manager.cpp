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

	double previewsX = 0;
	double previewsY = 0;
	double previewsYaw = 0;

	while (_running)
	{
		_robot->refresh();

		// ------------
		// Calculate deltas

		double deltaX = _robot->getX() - previewsX;
		double deltaY = _robot->getY() - previewsY;
		double deltaYaw = _robot->getYaw() - previewsYaw;

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

		Laser& laser = _robot->getLaser();
		_slamManager.update(deltaX, deltaY, deltaYaw, laser);

		// ------------
		// Save this iteration x, y ,yaw

		previewsX = _robot->getX();
		previewsY = _robot->getY();
		previewsYaw = _robot->getYaw();
	}

}

Manager::~Manager()
{
}
