/*
 * GoBackward.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef GORANDOM_H_
#define GORANDOM_H_


#include "Behavior.h"
#include "GoLeft.h"
#include "GoRight.h"
#include "../Robot.h"

class GoRandomDirection: public Behavior
{

public:
	GoRandomDirection(Robot* robot, GoLeft*	goLeft, GoRight* goRight);
	bool startCondition();
	bool stopCondition();
	void action();
	virtual ~GoRandomDirection();

private:
	GoLeft*		_goLeft;
	GoRight* 	_goRight;
	bool		_keep_moving;
	Behavior*	_cur_behavior;
};

#endif /* GOBACKWARD_H_ */
