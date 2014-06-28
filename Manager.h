/*
 * Manager.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef MANAGER_H_
#define MANAGER_H_
#include "Plans/Plan.h"
#include "Behaviors/Behavior.h"
#include "Robot.h"
#include "Point.h"
#include <vector>
#include <set>

using namespace std;

class Manager
{
	Robot* _robot;
	Plan* _plan;
	Behavior* _currentBehavior;
	bool _running;

public:
	Manager(Robot* robot, Plan* plan);
	void run();

	void stop()
	{
		_running = false;
	}

	virtual ~Manager();
};

#endif /* MANAGER_H_ */
