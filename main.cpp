/*
 * main.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include <iostream>
#include <unistd.h>

#include <sstream>
#include <string>
#include <set>

#include "Manager.h"
#include "Robot.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map.h"

using namespace std;

int main(int argc, char** argv)
{
	Robot robot("localhost", 6665);
	PlnObstacleAvoid pln(&robot);
	Manager m(&robot, &pln);
	m.run();

}

using namespace std;
using namespace PlayerCc;

#define LASER_RESOLUTION 0.36
#define LASER_MESURING_AREA 120
#define LASER_MAXIMUM_RANGE 2

float indexToDegree(int index) {
	return (index * LASER_RESOLUTION) - LASER_MESURING_AREA;
}

int degreeToIndex(float degree) {
	return (degree + LASER_MESURING_AREA) / LASER_RESOLUTION;
}

float degreeToRadian(float degree) {
	return degree * M_PI / 180.0;
}

float radianToDegree(float radian) {
	return radian * 180.0 / M_PI;
}

int main2(int argc, char** argv) {
	PlayerClient pc("localhost", 6665);
	Position2dProxy pp(&pc, 0);
	SonarProxy sp(&pc, 0);
	LaserProxy lp(&pc, 0);

	pp.SetSpeed(0, 0);
	pp.SetMotorEnable(true);

	Map worldMap(18, 40, 1);
	//pp.SetOdometry(0,0,0);

	for (int i = 0; i < 8; i++) {
		pc.Read();
	}

	//pp.GoTo(0,0,0);

	while (true) {
		try {
			pc.Read();

			set<string> obstacles;

			for (int i = 0; i < 666; i++) {

				float distance = lp[i];
				if (distance >= LASER_MAXIMUM_RANGE) {
					continue;
				}

				float angle_in_degree = indexToDegree(i);
				float angle_in_radian = degreeToRadian(angle_in_degree);

				float robotX = pp.GetXPos();
				float robotY = pp.GetYPos();

				float object_angle = angle_in_radian + pp.GetYaw();

				float obstacleX = distance * cos(object_angle) + robotX;
				float obstacleY = distance * sin(object_angle) + robotY;

				//obstacleX = robotX;
				//obstacleY=robotY;
				ostringstream key;

				// TODO ask yoda

				int robotMapCol = worldMap.convertXToColumn(robotX);
				int robotMapRow = worldMap.convertYToRow(robotY);

				int obstacleMapCol = worldMap.convertXToColumn(obstacleX);
				int obstacleMapRow = worldMap.convertYToRow(obstacleY);

				key << obstacleMapRow << " " << obstacleMapCol;

				//key << worldMap.convertYToColumn(obstacleY) << " " << worldMap.convertXToRow(obstacleX);

				obstacles.insert(key.str());

				//map.set(obstacleX, obstacleY, MAP_STATE_OBSTACLE);

			}

			std::set<string>::iterator it;
			for (it = obstacles.begin(); it != obstacles.end(); ++it) {
				string f = *it; // Note the "*" here
				cout << f << endl;
			}

			cout << " -------------------------- " << endl << endl << endl
					<< endl << endl << endl;

			// Print map
			//cout << map << endl;
		} catch (exception& ex) {
			cout << ex.what();
		}
		//cout << pp.GetXPos() << ' ' << pp.GetYPos() << pp.GetYaw() << endl;
	}

	pp.SetSpeed(0, 0);
	return 0;
}
