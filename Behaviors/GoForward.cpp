/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "GoForward.h"

GoForward::GoForward(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}
bool GoForward::startCondition()
{
	if(_robot->getLaserDistance(333) > 0.8)
		return true;
	return false;
}
void GoForward::action()
{
	if(_robot->getLaserDistance(333) > 3.0)
		_robot->setSpeed(1.0,0.0);
	else
		_robot->setSpeed(0.5,0.0);
}
bool GoForward::stopCondition()
{
	if(_robot->getLaserDistance(333) < 0.8)
		return true;
	return false;
}
GoForward::~GoForward() {
	// TODO Auto-generated destructor stub
}
