/*
 * Robot.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef ROBOT_H_
#define ROBOT_H_
#include <libplayerc++/playerc++.h>
using namespace PlayerCc;

class Robot {
	PlayerClient* _pc;
	Position2dProxy* _pp;
	LaserProxy* _lp;
public:
	Robot(char* ip, int port);
	void read();
	void setSpeed(float speed, float angularSpeed);
	float getLaserDistance(int index);
	virtual ~Robot();
};

#endif /* ROBOT_H_ */
