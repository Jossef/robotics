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
	return _robot->canMoveForward();
}
void GoForward::action()
{

}

bool GoForward::stopCondition()
{

}
GoForward::~GoForward() {

}
