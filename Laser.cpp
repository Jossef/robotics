/*
 * Laser.cpp
 *
 *  Created on: May 27, 2014
 *      Author: user
 */

#include "Laser.h"

double Laser::convertIndexToDegree(int index) const
{
	return (index * LASER_RESOLUTION) - LASER_MESURING_AREA;
}

int Laser::convertDegreeToIndex(double degree) const
{
	return (degree + LASER_MESURING_AREA) / LASER_RESOLUTION;
}

void Laser::getObstacles(double x, double y, double yaw, vector<Point>& obstacles) const
{
	// Clear the data structure
	obstacles.clear();

	for (unsigned int index = 0; index < _laserProxy.GetCount(); index++)
	{
		double distance = _laserProxy[index];

		// If the laser cannot seet an obstacle
		if (distance >= LASER_MAXIMUM_RANGE)
		{
			// let's move to the next sample
			continue;
		}

		double indexDegree = convertIndexToDegree(index);
		double indexRadian = MathHelper::ConvertDegreeToRadian(indexDegree);

		double obstacleRadian = indexRadian + yaw;

		double obstacleX = distance * cos(obstacleRadian) + x;
		double obstacleY = distance * sin(obstacleRadian) + y;

		Point point(obstacleX, obstacleY);

		obstacles.push_back(point);
	}
}

void Laser::getObstacles(vector<Point>& obstacles) const
{
	getObstacles(_robot.getX(), _robot.getY(), _robot.getYaw(), obstacles);
}

bool Laser::canRotate() const
{

	double minRotationDistance = LASER_MIN_ROTATION_DISTANCE;

	bool canRotate = true;

	for (unsigned int index = 0; index < _laserProxy.GetCount(); index++)
	{
		double distance = _laserProxy[index];

		if (distance < minRotationDistance)
		{
			canRotate = false;
			break;
		}
	}

	return canRotate;
}

bool Laser::canMoveForward() const
{
	double minForwardDistance = LASER_MIN_FORWARD_DISTANCE;

	bool canMoveForward = true;
	for (unsigned int index = LASER_MIN_FORWARD_START_INDEX; index < LASER_MIN_FORWARD_END_INDEX; index++)
	{
		double distance = _laserProxy[index];

		if (distance < minForwardDistance)
		{
			canMoveForward = false;
			break;
		}
	}

	return canMoveForward;
}

double Laser::GetRightRank() const
{
	double ret = 0;

	for (unsigned int index = LASER_MIN_FORWARD_END_INDEX; index < LASER_ARRAY_SIZE; index += 10)
	{
		ret += _laserProxy[index];
	}

	return ret;
}

double Laser::GetLeftRank() const
{
	double ret = 0;

	for (unsigned int index = 0; index < LASER_MIN_FORWARD_START_INDEX; index += 10)
	{
		ret += _laserProxy[index];
	}

	return ret;

}


