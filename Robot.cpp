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
	_laser = new Laser(*_laserProxy);
	_map = new Map();

	init();
}

void Robot::init()
{
	_positionProxy->SetOdometry(0,0,0);
	_positionProxy->SetMotorEnable(true);

	// Workaround to clear sensors
	for (int i = 0; i < 15; i++)
	{
		_playerClient->Read();
	}
}

Robot::~Robot()
{
	delete _laser;
	delete _map;
	delete _positionProxy;
	delete _laserProxy;
	delete _playerClient;
}

double Robot::getX() const
{
	double x = _positionProxy->GetXPos();

	if (DEMO_MODE)
	{
		srand(time(0));
		x += (rand() % DEMO_RANDOM)/DEMO_RANDOM_RATIO;
	}

	return x;
}

double Robot::getY() const
{
	double y = _positionProxy->GetYPos();

	if (DEMO_MODE)
	{
		srand(time(0));
		y += (rand() % DEMO_RANDOM)/DEMO_RANDOM_RATIO;
	}

	return y;
}

double Robot::getYaw() const
{
	double yaw = _positionProxy->GetYaw();

	if (DEMO_MODE)
	{
		srand(time(0));
		yaw += (rand() % DEMO_RANDOM)/DEMO_RANDOM_RATIO;
	}

	return yaw;
}

Map& Robot::getMap() const
{
	return *_map;
}

Laser& Robot::getLaser() const
{
	return *_laser;
}

void Robot::getObstacles(vector<Point>& obstacles) const
{
	_laser->getObstacles(getX(), getY(), getYaw(), obstacles);
}

bool Robot::canRotate() const
{
	return _laser->canRotate();
}

bool Robot::canMoveForward() const
{
	return _laser->canMoveForward();
}

void Robot::refresh()
{
	// Refresh Sensors buffers
	_playerClient->Read();

	// Handle new Obstacles
	vector<Point> obstacles;
	getObstacles(obstacles);

	Map& map = *_map;
	map.handleObstacles(*this, obstacles);
}

void Robot::setSpeed(double speed, double angularSpeed)
{
	_positionProxy->SetSpeed(speed, angularSpeed);
}

double Robot::get_right_rank() const
{
	return _laser->GetRightRank();
}

double Robot::get_left_rank() const
{
	return _laser->GetLeftRank();
}

