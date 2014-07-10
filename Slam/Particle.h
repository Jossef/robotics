/*
 * Particle.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#define PARTICLE_ERROR_RANGE 5

#include "../Laser.h"
#include <vector>
class Particle {
public:
	Particle();
	virtual ~Particle();

	void move(double xDelta, double yDelta, double yawDelta);
	void update(double deltaX, double deltaY, double deltaYaw, const Laser& laser);
	Particle GetNewParticle();
	Map& getMap() {return m_map;}
	double GetBelife() {return m_belife;}

private:
	void UpdateBelife();
	void UpdateMap();
	double m_Xpos;
	double m_Ypos;
	double m_Yaw;
	Map m_map;
	double m_belife;
};

#endif /* PARTICLE_H_ */
