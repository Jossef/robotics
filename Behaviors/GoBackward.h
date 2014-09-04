/*
 * GoBackward.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef GOBACKWARD_H_
#define GOBACKWARD_H_

#include "Behavior.h"
#include "../Robot.h"
class GoBackward: public Behavior
{

public:
	GoBackward(Robot* robot);

	bool startCondition();
	bool stopCondition();
	void action();
	virtual ~GoBackward();

private:
	int _steps_count;

};

#endif /* GOBACKWARD_H_ */
