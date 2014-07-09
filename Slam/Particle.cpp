/*
 * Particle.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#include "Particle.h"

Particle::Particle() :m_map(0,0){
	// TODO Auto-generated constructor stub

}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::Update(double xDelta, double yDelta, double yawDelta, vector<Point>& obstacles)
{
	//TODO change position by delta
	// TODO check obstacle with my current map
	// if failed lower score if ok increase. update map if needed with obstacles
	// should obstacles be represented with distance and angle?
	// how would i know the X and Y of an obstacle if i dont know mine


	// score should represent the number of particles i create from this particle
	// next generation gets a copy of my current map


}
Particle Particle::GetNewParticle()
{
}
