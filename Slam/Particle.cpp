/*
 * Particle.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "Particle.h"
#include <stdlib.h>
#include <time.h>

Particle::Particle() :
	_map()
{

}

void Particle::move(double deltaX, double deltaY, double deltaYaw)
{
	_x += deltaX;
	_y += deltaY;
	_yaw += deltaYaw;
}

void Particle::update(double deltaX, double deltaY, double deltaYaw, const Laser& laser)
{

	move(deltaX, deltaY, deltaYaw);

	vector<Point> obstacles;
	laser.getObstacles(_x, _y, _yaw, obstacles);

	// Check obstacle with my current map
	// if failed lower score if ok increase. update map if needed with obstacles

	int mismatcCount = _map.update(_x, _y, _yaw, laser);

	// TODO convert mismatch count into probability

	// score should represent the number of particles i create from this particle
	// next generation gets a copy of my current map

}

Particle Particle::create()
{
	Particle newPar;
	//initialize random seed
	srand(time(NULL));

	newPar._x = _x + rand() % PARTICLE_ERROR_RANGE;
	newPar._y = _y + rand() % PARTICLE_ERROR_RANGE;
	newPar._yaw = _yaw + rand() % PARTICLE_ERROR_RANGE;

	newPar._map = _map;

	return newPar;
}
