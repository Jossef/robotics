/*
 * Laser.h
 *
 *  Created on: May 27, 2014
 *      Author: user
 */

#ifndef LASER_H_
#define LASER_H_

#include <math.h>
#include <libplayerc++/playerc++.h>
#include "Point.h"
#include "Configuration.h"
#include "Robot.h"
#include "MathHelper.h"
#include "Map.h"

#include <vector>

using namespace PlayerCc;
using namespace std;

class Robot;
class Map;

class Laser
{

private:
	LaserProxy& _laserProxy;
	Robot& _robot;

	double convertIndexToDegree(int index) const;
	int convertDegreeToIndex(double degree) const;

public:

	Laser(LaserProxy& laserProxy, Robot& robot) :
		_laserProxy(laserProxy), _robot(robot)
	{
	}

	void getObstacles(double maximumDistance, vector<Point>& obstacles) const;

	bool canRotate() const;
	bool canMoveForward() const;

	void updateMap(Map& map) const;

	virtual ~Laser()
	{
	}
};

#endif /* LASER_H_ */
