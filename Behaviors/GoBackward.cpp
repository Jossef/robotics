/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "GoBackward.h"

GoBackward::GoBackward(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}
bool GoBackward::startCondition()
{
	if(_robot->getLaserDistance(333) > 0.8)
		return true;
	return false;
}
void GoBackward::action()
{
	_robot->setSpeed(0.0,-0.5);
}
bool GoBackward::stopCondition()
{
	if(_robot->getLaserDistance(333) < 0.8)
		return true;
	return false;
}
GoBackward::~GoBackward() {
	// TODO Auto-generated destructor stub
}
