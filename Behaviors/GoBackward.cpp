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

	return false;
}
void GoBackward::action()
{

}
bool GoBackward::stopCondition()
{
	return false;
}
GoBackward::~GoBackward() {
	// TODO Auto-generated destructor stub
}
