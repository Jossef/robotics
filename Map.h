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
#include <math.h>
#include <iostream>

using namespace std;

class Map
{
	float _resolution;
	int _rows;
	int _columns;
	Matrix<int> _matrix;

public:
	Map(int rows, int columns, float resolution = 1.0);
	virtual ~Map();

	int convertYToRow(float y) const;
	int convertXToColumn(float x) const;

	Map(unsigned int rows, unsigned int columns, float resolution);

	// By x, y of world
	int get(float x, float y) const;
	void set(float x, float y, int value);

	// By row and column
	int get(int row, int column) const;
	void set(int row, int column, int value);

	friend std::ostream& operator<< (std::ostream& stream, const Map& matrix);
};

#endif /* MAP_H_ */
