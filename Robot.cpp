/*
 * Robot.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "Robot.h"

Robot::Robot(char* ip, int port){
	// TODO Auto-generated constructor stub
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_pp->SetMotorEnable(true);
	int i;
	for(i=0;i<15;i++)
		_pc->Read();
}
void Robot::read()
{
	_pc->Read();
}
void Robot::setSpeed(float speed, float angularSpeed)
{
	_pp->SetSpeed(speed,angularSpeed);
}
float Robot::getLaserDistance(int index)
{
	return _lp->GetRange(index);
}
Robot::~Robot() {
	// TODO Auto-generated destructor stub
}
