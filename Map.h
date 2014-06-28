/*
 * Map.h
 *
 *  Created on: Apr 22, 2014
 *      Author: user
 */

#ifndef MAP_H_
#define MAP_H_

#define MAP_STATE_CLEAR 0
#define MAP_STATE_OBSTACLE 1
#define MAP_STATE_UNKNOWN 2

#include "Matrix.h"
#include "Robot.h"
#include <math.h>
#include <iostream>

using namespace std;

class Robot;

class Map
{
	float _resolution;
	int _rows;
	int _columns;
	Matrix<int> _matrix;

public:
	Map(int rows, int columns, double resolution = 1.0);
	virtual ~Map();

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

	void handleObstacles(const Point& robotPoint, const vector<Point>& obstacles);
	void handleObstacles(Robot& robot, const vector<Point>& obstacles);


	friend std::ostream& operator<< (std::ostream& stream, const Map& matrix);
};

#endif /* MAP_H_ */
