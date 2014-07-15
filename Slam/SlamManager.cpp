/*
 * SlamManager.cpp
 *
 *  Created on: Jul 10, 2014
 *      Author: user
 */

#include "SlamManager.h"

SlamManager::SlamManager()
{
	for (int i = 0; i < INIT_PARTICLE_COUNT; i++)
	{
		//initialize random seed
		srand(time(NULL));

		double particleX =  (rand() % PARTICLE_SPREAD_MODULO) / PARTICLE_SPREAD_MODULO;
		double particleY = (rand() % PARTICLE_SPREAD_MODULO) / PARTICLE_SPREAD_MODULO;
		double particleYaw = (rand() % PARTICLE_SPREAD_MODULO) / PARTICLE_SPREAD_MODULO;

		Particle newParticle;
		newParticle.move(particleX,particleY,particleYaw);
		_particles.push_back(newParticle);
	}
}

Map& SlamManager::update(double deltaX, double deltaY, double deltaYaw, const Laser& laser)
{
	list<Particle> particlesToAdd;
	list<Particle> toRemove;
	Particle& bestParticle = *_particles.begin();

	// Loop the existing particles
	for (list<Particle>::iterator iter = _particles.begin(); iter != _particles.end(); iter++)
	{
		Particle& particle = *iter;

		double belief = particle.update(deltaX, deltaY, deltaYaw, laser);

		// If the particle should be killed
		if (belief <= PARTICLE_KILL_THRESHOLD && _particles.size() != 0)
		{
			// save the particle for removal
			toRemove.push_back(*iter);
		}
		// If we can produce more particles
		// If particle should duplicate
		else if (belief >= PARTICLE_BIRTH_THRESHOLD &&
				(_particles.size() + particlesToAdd.size()) <= PARTICLE_COUNT)
		{
			Particle newParticle = particle.create();
			_particles.push_back(particle);
		}

		// get best particle for creation of more
		if (belief > bestParticle.getBelief())
		{
			bestParticle = *iter;
		}
	}

	// deleting the particles
	for (list<Particle>::iterator iter = toRemove.begin(); iter != toRemove.end(); iter++)
	{
		_particles.remove(*iter);
	}

	// Creating from the best part
	for (size_t parCount = _particles.size(); parCount <= PARTICLE_COUNT; parCount++)
	{
		Particle newParticle = bestParticle.create();
		_particles.push_back(newParticle);
	}

	return bestParticle.getMap();
}

SlamManager::~SlamManager()
{
}
