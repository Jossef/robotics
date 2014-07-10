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
#include "Map.h"
#include <libplayerc++/playerc++.h>
#include <vector>

using namespace std;
using namespace PlayerCc;

class Laser;
class Map;


class Robot {
	PlayerClient* _playerClient;
	Position2dProxy* _positionProxy;
	LaserProxy* _laserProxy;
	Laser* _laser;
	Map* _map;

	void init();

public:
	Robot(char* ip, int port);

	double getX() const;
	double getY() const;
	double getYaw() const;
	Map& getMap() const;
	Laser& getLaser() const;

	void getObstacles(vector<Point>& obstacles) const;

	bool canRotate() const;
	bool canMoveForward() const;

	void refresh();
	void setSpeed(double speed, double angularSpeed);



	virtual ~Robot();
};

#endif /* ROBOT_H_ */
