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
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

class Particle
{
private:

	double _x;
	double _y;
	double _yaw;
	Map _map;
	double _belief;
	double probabilityMove(double deltaX, double deltaY, double deltaYaw);


public:
	Particle();

	void move(double deltaX, double deltaY, double deltaYaw);
	Particle create();
	double update(double deltaX, double deltaY, double deltaYaw, const Laser& laser);
	double getBelief() const;
	Map& getMap();

	bool operator ==(const Particle& ref);
};

#endif /* PARTICLE_H_ */
