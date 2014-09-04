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
	try
	{

		Robot robot("localhost", 6665);
		PlnObstacleAvoid pln(&robot);
		Manager m(&robot, &pln);
		m.run();

	}
	catch (exception& ex)
	{
		cout << ex.what();
	}
}
