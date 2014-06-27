/*
 * Robot.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Point.h"
#include "Laser.h"
#include <libplayerc++/playerc++.h>
#include <vector>

using namespace std;
using namespace PlayerCc;

class Laser;

class Robot {
	PlayerClient* _playerClient;
	Position2dProxy* _positionProxy;
	LaserProxy* _laserProxy;
	Laser* _laser;

public:
	Robot(char* ip, int port);

	double getX();
	double getY();
	double getYaw();

	void getObstacles(vector<Point>& obstacles);

	bool canRotate();
	bool canMoveForward();

	void refresh();
	void setSpeed(float speed, float angularSpeed);

	virtual ~Robot()
	{
		delete _laser;
		delete _positionProxy;
		delete _laserProxy;
		delete _playerClient;
	}
};

#endif /* ROBOT_H_ */
