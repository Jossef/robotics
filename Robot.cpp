/*
 * Robot.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "Robot.h"

Robot::Robot(char* ip, int port)
{
	_playerClient = new PlayerClient(ip, port);
	_positionProxy = new Position2dProxy(_playerClient);
	_laserProxy = new LaserProxy(_playerClient);
	_laser = new Laser(*_laserProxy, *this);

	_positionProxy->SetMotorEnable(true);

	// Workaround to clear sensors
	for (int i = 0; i < 15; i++)
	{
		_playerClient->Read();
	}
}

double Robot::getX()
{
	return _positionProxy->GetXPos();
}

double Robot::getY()
{
	return _positionProxy->GetYPos();
}

double Robot::getYaw()
{
	return _positionProxy->GetYaw();
}

void Robot::getObstacles(vector<Point>& obstacles)
{
	_laser->getObstacles(LASER_OBSTACLE_DISTANCE, obstacles);
}

bool Robot::canRotate()
{
	return _laser->canRotate();
}

bool Robot::canMoveForward()
{
	return _laser->canMoveForward();
}

void Robot::refresh()
{
	_playerClient->Read();
}

void Robot::setSpeed(float speed, float angularSpeed)
{
	_positionProxy->SetSpeed(speed, angularSpeed);
}

