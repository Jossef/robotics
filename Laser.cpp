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

void Laser::getObstacles(double maximumDistance, vector<Point>& obstacles) const
{

	// Clear the data structure
	obstacles.clear();

	double robotX = _robot.getX();
	double robotY = _robot.getY();
	double robotYaw = _robot.getYaw();

	for (unsigned int index = 0; index < _laserProxy.GetCount(); index++)
	{
		double distance = _laserProxy[index];

		if (distance >= LASER_MAXIMUM_RANGE)
		{
			continue;
		}

		double indexDegree = convertIndexToDegree(index);
		double indexRadian = MathHelper::ConvertDegreeToRadian(indexDegree);

		double obstacleRadian = indexRadian + robotYaw;

		double obstacleX = distance * cos(obstacleRadian) + robotX;
		double obstacleY = distance * sin(obstacleRadian) + robotY;

		Point point(obstacleX, obstacleY);

		obstacles.push_back(point);
	}
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

void Laser::updateMap(Map& map) const
{

}
