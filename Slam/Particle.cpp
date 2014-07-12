#include "Particle.h"

Particle::Particle() :
	_map()
{
	_belief = 0.9;
}

void Particle::move(double deltaX, double deltaY, double deltaYaw)
{
	_x += deltaX;
	_y += deltaY;
	_yaw += deltaYaw;
}

void Particle::update(double deltaX, double deltaY, double deltaYaw, const Laser& laser)
{
	// ---------------
	// Update Particle x, y, yaw

	move(deltaX, deltaY, deltaYaw);

	// TODO preBelief = probmov
	double previewsBelief = _belief * 1;

	// ---------------
	// Update Map

	int mismatchCount = _map.update(_x, _y, _yaw, laser);

	// ---------------
	// Update Belief

	// Converting mismatch count into probability
	// by 1/mismatch
	// if high mismatches - we will get a lower belief
	// otherwise, we will get stable belief

	// If there are no mismatches, lets verify that we don't divide by 0
	mismatchCount = std::max(mismatchCount, 1);

	_belief = PARTICLE_MAGIC_NUMBER * previewsBelief * (1 / mismatchCount);

	// Create Children Particles
	for (int i = 0; i < PARTICLE_CHILEDS_COUNT; i++)
	{

	}

	// Should kill
	if (_belief <= PARTICLE_KILL_BELIEF)
	{
		// Kill the particle
	}
}

Particle Particle::create()
{
	Particle newPar;
	//initialize random seed
	srand(time(NULL));

	newPar._x = _x + rand() % PARTICLE_ERROR_RANGE;
	newPar._y = _y + rand() % PARTICLE_ERROR_RANGE;
	newPar._yaw = _yaw + rand() % PARTICLE_ERROR_RANGE;

	// Next generation gets a copy of my current map
	// This is done by copy constructor
	newPar._map = _map;

	return newPar;
}
