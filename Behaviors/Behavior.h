/*
 * Behavior.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_
#include "../Robot.h"
#include <vector>

using namespace std;

class Behavior {
	vector<Behavior*> _nextBehaviors;
protected:
	Robot* _robot;
public:
	Behavior(Robot* robot);
	virtual bool startCondition() = 0;
	virtual bool stopCondition() = 0;
	virtual void action() = 0;
	Behavior* addNextBehavior(Behavior* behavior);
	Behavior* getNextBehavior();
	virtual ~Behavior();
};

#endif /* BEHAVIOR_H_ */
