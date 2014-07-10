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
	m_map(0, 0)
{
	// TODO Auto-generated constructor stub

}

Particle::~Particle()
{
	// TODO Auto-generated destructor stub
}

void Particle::move(double xDelta, double yDelta, double yawDelta)
{
	m_Xpos += xDelta;
	m_Ypos += yDelta;
	m_Yaw += yawDelta;
}

void Particle::update(double deltaX, double deltaY, double deltaYaw, const Laser& laser)
{
	vector<Point> obstacles;
	laser.getObstacles(m_Xpos, m_Ypos, m_Yaw, obstacles);
	// TODO check obstacle with my current map
	// if failed lower score if ok increase. update map if needed with obstacles


	// score should represent the number of particles i create from this particle
	// next generation gets a copy of my current map


}
Particle Particle::GetNewParticle()
{
	Particle newPar;
	//initialize random seed
	srand(time(NULL));
	newPar.m_Xpos = m_Xpos + rand() % PARTICLE_ERROR_RANGE;
	newPar.m_Ypos = m_Ypos + rand() % PARTICLE_ERROR_RANGE;
	newPar.m_Yaw = m_Yaw + rand() % PARTICLE_ERROR_RANGE;

	newPar.m_map = m_map;

	return newPar;
}
