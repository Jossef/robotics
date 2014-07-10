/*
 * SlamManager.cpp
 *
 *  Created on: Jul 10, 2014
 *      Author: user
 */

#include "SlamManager.h"

SlamManager::SlamManager()
{

}

void SlamManager::update(double deltaX, double deltaY, double deltaYaw, const Laser& laser)
{

	for (vector<Particle>::iterator iter = _particles.begin(); iter != _particles.end(); iter++)
	{
		Particle& particle = *iter;
		particle.update(deltaX, deltaY, deltaYaw, laser);


		// TODO threshold and shit https://drive.google.com/#folders/0B9RF6zZ3qfHXakF5MDZvcTZieVU

	}

}

SlamManager::~SlamManager()
{
}
