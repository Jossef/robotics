/*
 * Map.h
 *
 *  Created on: Apr 22, 2014
 *      Author: user
 */

#ifndef MAP_H_
#define MAP_H_

#define MAP_STATE_UNKNOWN 0
#define MAP_STATE_OBSTACLE 1
#define MAP_STATE_CLEAR 2

#include "Matrix.h"
#include "Robot.h"
#include "Point.h"
#include "Laser.h"
#include <math.h>
#include <iostream>

using namespace std;

class Robot;
class Laser;

class Map
{
	float _resolution;
	int _rows;
	int _columns;
	Matrix<int> _matrix;

public:
	Map & operator =(const Map& m);
	Map(int rows = MAP_ROWS, int columns = MAP_COLUMNS, double resolution = MAP_RESOLUTION);

	int convertYToRow(double y) const;
	int convertXToColumn(double x) const;

	Map(unsigned int rows, unsigned int columns, double resolution);

	// By x, y of world
	int get(double x, double y) const;
	void set(double x, double y, int value);
	void set(const Point& point, int value);

	// By row and column
	int get(int row, int column) const;
	void set(int row, int column, int value);

	// Tells if there is a mismatch between the new value and the existing value
	bool isMismatch(const Point& point, int value, bool & isUnknown);
	bool isMismatch(int row, int column, int value, bool & isUnknown);

	// Returns match percentage
	double handleObstacles(const Point& initalPoint, const vector<Point>& obstacles);
	double handleObstacles(Robot& robot, const vector<Point>& obstacles);

	// Returns match percentage
	double update(double x, double y, double yaw, const Laser& laser);

	friend std::ostream& operator<< (std::ostream& stream, const Map& matrix);
};

#endif /* MAP_H_ */
