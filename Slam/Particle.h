/*
 * Particle.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "../Configuration.h"
#include "../Laser.h"
#include <vector>
class Particle
{
private:

	double _x;
	double _y;
	double _yaw;
	Map _map;
	double _belief;

	void move(double deltaX, double deltaY, double deltaYaw);

public:
	Particle();

	Particle create();

	void update(double deltaX, double deltaY, double deltaYaw, const Laser& laser);

	Map& getMap()
	{
		return _map;
	}

	double GetBelife()
	{
		return _belief;
	}

};

#endif /* PARTICLE_H_ */
