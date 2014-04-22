/*
 * GoRight.h
 *
 *  Created on: Mar 26, 2014
 *      Author: user
 */

#ifndef GOLEFT_H_
#define GOLEFT_H_

#include "Behavior.h"
#include "../Robot.h"

class GoLeft: public Behavior {
public:
	GoLeft(Robot* robot);
	bool startCondition();
	bool stopCondition();
	void action();
	virtual ~GoLeft();
};

#endif /* GOLEFT_H_ */
