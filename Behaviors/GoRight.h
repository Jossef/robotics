/*
 * GoRight.h
 *
 *  Created on: Mar 26, 2014
 *      Author: user
 */

#ifndef GORIGHT_H_
#define GORIGHT_H_

#include "Behavior.h"
#include "../Robot.h"

class GoRight: public Behavior {
public:
	GoRight(Robot* robot);
	bool startCondition();
	bool stopCondition();
	void action();
	virtual ~GoRight();
};

#endif /* GORIGHT_H_ */
