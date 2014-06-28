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
	_map = new Map(MAP_ROWS, MAP_COLUMNS, MAP_RESOLUTION);

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
	return _positionProxy->GetXPos();
}

double Robot::getY() const
{
	return _positionProxy->GetYPos();
}

double Robot::getYaw() const
{
	return _positionProxy->GetYaw();
}

Map& Robot::getMap() const
{
	return *_map;
}

void Robot::getObstacles(vector<Point>& obstacles) const
{
	_laser->getObstacles(LASER_OBSTACLE_DISTANCE, obstacles);
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
	cout << map << endl;
}

void Robot::setSpeed(double speed, double angularSpeed)
{
	_positionProxy->SetSpeed(speed, angularSpeed);
}

