/*
 * Particle.h
 *
 *  Created on: Jul 9, 2014
 *      Author: user
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "../Map.h"
#include "../Point.h"
#include <vector>
class Particle {
public:
	Particle();
	virtual ~Particle();

	void Update(double xDelta, double yDelta, double yawDelta, vector<Point>& obstacles);
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
