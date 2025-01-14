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

	double convertIndexToDegree(int index) const;
	int convertDegreeToIndex(double degree) const;

public:

	Laser(LaserProxy& laserProxy) : _laserProxy(laserProxy)
	{
	}

	
	void getObstacles(double x, double y, double yaw, vector<Point>& obstacles) const;

	bool canRotate() const;
	bool canMoveForward() const;
	
	
	double GetRightRank() const;
	double GetLeftRank() const;

	virtual ~Laser()
	{
	}
};

#endif /* LASER_H_ */
