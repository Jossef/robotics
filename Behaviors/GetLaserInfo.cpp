/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "GetLaserInfo.h"

GetLaserInfo::GetLaserInfo(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}
bool GetLaserInfo::startCondition()
{
	if(_robot->getLaserDistance(333) > 0.8)
		return true;
	return false;
}
void GetLaserInfo::action()
{
	if(_robot->getLaserDistance(333) > 3.0)
		_robot->setSpeed(1.0,0.0);
	else
		_robot->setSpeed(0.5,0.0);
}
bool GetLaserInfo::stopCondition()
{
	if(_robot->getLaserDistance(333) < 0.8)
		return true;
	return false;
}
GetLaserInfo::~GetLaserInfo() {
	// TODO Auto-generated destructor stub
}
