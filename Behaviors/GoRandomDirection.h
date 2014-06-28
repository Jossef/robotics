/*
 * GoBackward.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef GOBACKWARD_H_
#define GOBACKWARD_H_

#include "Behavior.h"
#include "GoLeft.h"
#include "GoRight.h"
#include "../Robot.h"
class GoRandomDirection: public Behavior
{
	GoLeft _goLeft;
	GoRight _goRight;

public:
	GoRandomDirection(Robot* robot);
	bool startCondition();
	bool stopCondition();
	void action();
	virtual ~GoRandomDirection();
};

#endif /* GOBACKWARD_H_ */
