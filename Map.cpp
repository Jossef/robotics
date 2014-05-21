/*
 * Map.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: user
 */

#include "Map.h"

Map::Map(int rows, int columns, float resolution)
{
	// TODO: input checks

	_resolution = resolution;

	float fixed_resolution = 1 / resolution;

	_rows = ceil(rows * fixed_resolution);
	_columns= ceil(columns * fixed_resolution);

	_matrix.init(_rows, _columns, MAP_STATE_UNKNOWN);
}

Map::~Map()
{
}

int Map::get(float x, float y) const
{
	// TODO: input checks

	// Convert x and y to row and column
	int row = convertYToRow(y);
	int column = convertXToColumn(x);

	return get(row,column);
}

void Map::set(float x, float y, int value)
{
	// TODO: input checks

	// Convert x and y to row and column
	int row = convertYToRow(y);
	int column = convertXToColumn(x);

	set(row,column,value);
}

int Map::get(int row, int column) const
{
	// TODO: input checks

	return _matrix(row,column);
}

void Map::set(int row, int column, int value)
{
	// TODO: input checks

	_matrix(row,column) = value;
}


std::ostream& operator<<(ostream &os, const Map& map)
{

	for (int i = 0; i < map._rows; i++)
	{
		for (int j = 0; j < map._columns; j++)
		{
			if (j > 0)
			{
				// Cell separator
				os << " | ";
			}

			os << map.get(i, j);
		}

		os << endl << endl;
	}

	return os;
}

/*
 * X, Y may be nagative
 *
 * in our map, 0 is the middle
 * any negative value is relative to the left
 * and any positive value is relative to the right
 *
 * -  -  -  -  0  +  +  +  +
 *-4 -3 -2 -1     1  2  3  4
 *------------------------------
 * 0  1  2  3  4  5  6  7  8
 *
 */


int Map::convertYToRow(float y) const
{
	float res = 1 / _resolution;
	float rows = _rows;
	//float value = ceil((columns ) / 2) + (x * res);
	//return floor(value);

	int value = (rows / 2) - (y * res);
	return value;
}

int Map::convertXToColumn(float x) const
{
	float res = 1 / _resolution;
	float columns = _columns;
	//float value = ceil((rows ) / 2) - (y * res);
	//return floor(value);

	int value = (columns / 2) + (x * res);
	return value;
}

