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
	vector<Particle> particlesToAdd;
	int particleCount = _particles.size();

	// Loop the existing particles
	for (vector<Particle>::iterator iter = _particles.begin(); iter != _particles.end(); iter++)
	{
		Particle& particle = *iter;
		particle.update(deltaX, deltaY, deltaYaw, laser);

		double belief = particle.getBelief();

		// If the particle should be killed
		if (belief <= PARTICLE_KILL_THRESHOLD)
		{
			// Remove the particle
			iter = _particles.erase(iter);
		}
		// If we can produce more particles
		// If particle should duplicate
		else if (belief >= PARTICLE_BIRTH_THRESHOLD && (particleCount + particlesToAdd.size()) <= PARTICLE_COUNT)
		{
			Particle newParticle = particle.create();
			particlesToAdd.push_back(particle);
		}
	}

	// Check if there are additional particles to add
	particleCount = particleCount + particlesToAdd.size();

	for (int i = particleCount; i < PARTICLE_COUNT; i++)
	{
		//initialize random seed
		srand(time(NULL));

		double particleX = deltaX + (rand() % PARTICLE_SPREAD_MODULO) / PARTICLE_SPREAD_MODULO;
		double particleY = deltaY + (rand() % PARTICLE_SPREAD_MODULO) / PARTICLE_SPREAD_MODULO;
		double particleYaw = deltaYaw + (rand() % PARTICLE_SPREAD_MODULO) / PARTICLE_SPREAD_MODULO;

		Particle particle;
		particle.update(particleX, particleY, particleYaw, laser);

		particlesToAdd.push_back(particle);
	}

	// Iterate the new particles
	for (vector<Particle>::iterator iter = particlesToAdd.begin(); iter != particlesToAdd.end(); iter++)
	{
		Particle& particle = *iter;
		_particles.push_back(particle);
	}

}

SlamManager::~SlamManager()
{
}
