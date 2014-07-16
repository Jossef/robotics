/*
 * SlamManager.h
 *
 *  Created on: Jul 10, 2014
 *      Author: user
 */

#ifndef SLAMMANAGER_H_
#define SLAMMANAGER_H_

#include "../Laser.h"
#include "Particle.h"
#include <list>

using namespace std;

class SlamManager
{
private:

	list<Particle*> _particles;

public:
	SlamManager();

	Map& update(double deltaX, double deltaY, double deltaYaw, const Laser& laser);

	virtual ~SlamManager();
};

#endif /* SLAMMANAGER_H_ */
