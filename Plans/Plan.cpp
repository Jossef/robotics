/*
 * Plan.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "Plan.h"

Plan::Plan(Robot* robot)
{

	_robot = robot;
}

Plan::~Plan()
{
	const int size = _behaviors.size();

	for (int index = 0; index < size; ++index)
	{
		delete _behaviors[index];
	}
}
