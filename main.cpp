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
#include "MathHelper.h"
#include "Point.h"

using namespace std;


int main(int argc, char** argv)
{
	vector<Point> intermediatePoints;
	MathHelper::GetIntermediatePoints(Point(-5,20), Point(1,5), 0.5, intermediatePoints);

	vector<Point >::const_iterator iter = intermediatePoints.begin();
	for(;iter!=intermediatePoints.end();iter++)
	{
		cout << (*iter).first << " , " << (*iter).second << endl;
	}
}

int main4(int argc, char** argv)
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

double indexToDegree(int index) {
	return (index * LASER_RESOLUTION) - LASER_MESURING_AREA;
}

int degreeToIndex(double degree) {
	return (degree + LASER_MESURING_AREA) / LASER_RESOLUTION;
}

double degreeToRadian(double degree) {
	return degree * M_PI / 180.0;
}

double radianToDegree(double radian) {
	return radian * 180.0 / M_PI;
}

int main3(int argc, char** argv) {
	PlayerClient pc("localhost", 6665);
	Position2dProxy pp(&pc, 0);
	SonarProxy sp(&pc, 0);
	LaserProxy lp(&pc, 0);

	pp.SetSpeed(0, 0);
	pp.SetMotorEnable(true);

	Map worldMap(18, 40, 1);
	pp.SetOdometry(0,0,0);

	for (int i = 0; i < 8; i++) {
		pc.Read();
	}

	//pp.GoTo(0,0,0);

	while (true) {
		try {
			pc.Read();

			set<string> obstacles;

			for (int i = 0; i < 666; i++) {

				double distance = lp[i];
				if (distance >= LASER_MAXIMUM_RANGE) {
					continue;
				}

				double angle_in_degree = indexToDegree(i);
				double angle_in_radian = degreeToRadian(angle_in_degree);

				double robotX = pp.GetXPos();
				double robotY = pp.GetYPos();

				double object_angle = angle_in_radian + pp.GetYaw();

				double obstacleX = distance * cos(object_angle) + robotX;
				double obstacleY = distance * sin(object_angle) + robotY;

				ostringstream key;

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
