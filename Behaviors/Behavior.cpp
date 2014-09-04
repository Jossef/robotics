/*
 * Behavior.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "Behavior.h"

Behavior::Behavior(Robot* robot)
{
	_robot = robot;
}

Behavior* Behavior::addNextBehavior(Behavior* behavior)
{
	this->_nextBehaviors.push_back(behavior);
}

Behavior* Behavior::getNextBehavior()
{
	for (vector<Behavior*>::const_iterator iter = _nextBehaviors.begin(); iter != _nextBehaviors.end(); iter++)
	{
		Behavior* currentBehavior = *iter;
		if (currentBehavior->startCondition())
		{
			return currentBehavior;
		}
	}

	return NULL;
}

Behavior::~Behavior()
{
}
