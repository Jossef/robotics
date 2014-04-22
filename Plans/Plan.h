/*
 * Plan.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef PLAN_H_
#define PLAN_H_
#include "../Behaviors/Behavior.h"
#include <vector>
using namespace std;

class Plan {
protected:
	vector<Behavior*> _behaviors;
	Robot* _robot;
	Behavior* _startBehavior;
public:
	Plan(Robot* robot);
	virtual Behavior* startBehavior()=0;
	virtual ~Plan();
};

#endif /* PLAN_H_ */
