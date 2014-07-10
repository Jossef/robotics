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
#include <vector>

using namespace std;

class SlamManager
{

vector<Particle> _particles;

public:
	SlamManager();

	void update(double deltaX, double deltaY, double deltaYaw, const Laser& laser);

	virtual ~SlamManager();
};

#endif /* SLAMMANAGER_H_ */
