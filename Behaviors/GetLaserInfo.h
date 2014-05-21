/*
 * GetLaserInfo.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef GetLaserInfo_H_
#define GetLaserInfo_H_

#include "Behavior.h"
#include "../Robot.h"
class GetLaserInfo: public Behavior {
public:
	GetLaserInfo(Robot* robot);
	bool startCondition();
	bool stopCondition();
	void action();
	virtual ~GetLaserInfo();
};

#endif /* GetLaserInfo_H_ */
