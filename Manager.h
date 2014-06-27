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

class Manager {
	Robot* _robot;
	Plan* _plan;
	Behavior* _currentBehavior;
public:
	Manager(Robot* robot, Plan* plan);
	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
