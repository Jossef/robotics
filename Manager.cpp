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
	_curr = plan->startBehavior();
	// TODO Auto-generated constructor stub

}
void Manager::run()
{
	_robot->read();
	if(_curr->startCondition() == false)
		return;
	_curr->action();
	while(true)
	{
		_robot->read();
		if(_curr->stopCondition())
		{
			_curr = _curr->getNextBehavior();
			if(!_curr)
				break;
		}
		_curr->action();
	}

}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}
