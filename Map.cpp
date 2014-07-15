/*
 * Map.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: user
 */

#include "Map.h"

Map::Map(int rows, int columns, double resolution)
{
	// TODO: input checks

	_resolution = resolution;

	float fixed_resolution = 1 / resolution;

	_rows = ceil(rows * fixed_resolution);
	_columns = ceil(columns * fixed_resolution);

	_matrix.init(_rows, _columns, MAP_STATE_UNKNOWN);
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

int Map::convertYToRow(double y) const
{
	int value = (_rows / 2) - (y / _resolution);

	return value;
}

int Map::convertXToColumn(double x) const
{
	int value = (_columns / 2) + (x / _resolution);
	return value;
}

int Map::get(double x, double y) const
{
	// TODO: input checks

	// Convert x and y to row and column
	int row = convertYToRow(y);
	int column = convertXToColumn(x);

	return get(row, column);
}

void Map::set(double x, double y, int value)
{
	// TODO: input checks

	// Convert x and y to row and column
	int row = convertYToRow(y);
	int column = convertXToColumn(x);

	set(row, column, value);
}

int Map::get(int row, int column) const
{
	// TODO: input checks

	return _matrix(row, column);
}

void Map::set(int row, int column, int value)
{
	int previews_value = get(row, column);

	switch (previews_value)
	{
	case (MAP_STATE_OBSTACLE):
		// Ignore this cell update

		break;

	default:
		_matrix(row, column) = value;
		break;
	}
}

void Map::set(const Point& point, int value)
{
	int pointRow = convertYToRow(point.getY());
	int pointColumn = convertXToColumn(point.getX());

	set(pointRow, pointColumn, value);
}

bool Map::isMismatch(int row, int column, int value)
{
	int previews_value = get(row, column);

	// For unknown values we do not care what is the new value
	if (previews_value == MAP_STATE_UNKNOWN)
	{
		return false;
	}

	// If they are not equals then this is a mismatch
	bool mismatch = !(previews_value == value);

	return mismatch;
}

bool Map::isMismatch(const Point& point, int value)
{
	// Convert x and y to row and column
	int pointRow = convertYToRow(point.getY());
	int pointColumn = convertXToColumn(point.getX());

	return isMismatch(pointRow, pointColumn, value);
}

// Print operator
std::ostream& operator<<(ostream &os, const Map& map)
{
	for (int i = 0; i < map._rows; i++)
	{
		for (int j = 0; j < map._columns; j++)
		{

			int value = map.get(i, j);

			switch (value)
			{
			case (MAP_STATE_CLEAR):
				os << " ";
				break;

			case (MAP_STATE_OBSTACLE):
				os << "█";
				break;

			case (MAP_STATE_UNKNOWN):
				os << "░";
				break;
			}
		}

		os << endl;
	}

	return os;
}

int Map::handleObstacles(const Point& initalPoint, const vector<Point>& obstacles)
{
	//////////////////////////////////////////////////
	// TODO: DELETE THIS LINE - ONLY FOR TESTING
	int num_of_obstacles = obstacles.size();
	//////////////////////////////////////////////////


	int mismatchCount = 0;

	vector<Point> freePointsToFlush;
	set(initalPoint, MAP_STATE_CLEAR);

	for (std::vector<Point>::const_iterator it = obstacles.begin(); it != obstacles.end(); ++it)
	{
		const Point& obstaclePoint = *it;

		if (isMismatch(obstaclePoint, MAP_STATE_OBSTACLE))
		{
			mismatchCount++;
		}

		// Get intermediate points (the points between the robot and the obstacle)
		vector<Point> intermediatePoints;
		MathHelper::GetIntermediatePoints(initalPoint, obstaclePoint, MAP_INTERMEDIATE_POINT_DISTANCE, intermediatePoints);

		////////////////////////////////////////////////
		// TODO: DELETE THIS LINE - ONLY FOR TESTING
		int num_of_intermediatePoints = intermediatePoints.size();
		///////////////////////////////////////////////


		// Enumerate Intermediate Points,
		// Set each intermediate Point to 'CLEAR' map state
		for (std::vector<Point>::const_iterator it2 = intermediatePoints.begin(); it2 != intermediatePoints.end(); ++it2)
		{
			const Point& intermediatePoint = *it2;

			if (isMismatch(intermediatePoint, MAP_STATE_CLEAR))
			{
				mismatchCount++;
			}

			freePointsToFlush.push_back(intermediatePoint);
		}
	}

	for (std::vector<Point>::const_iterator it = obstacles.begin(); it != obstacles.end(); ++it)
	{
		set(*it, MAP_STATE_OBSTACLE);
	}

	for (std::vector<Point>::const_iterator it = freePointsToFlush.begin(); it != freePointsToFlush.end(); ++it)
	{
		set(*it, MAP_STATE_CLEAR);
	}
	return mismatchCount;
}

int Map::handleObstacles(Robot& robot, const vector<Point>& obstacles)
{
	double robotX = robot.getX();
	double robotY = robot.getY();

	Point initalPoint(robotX, robotY);

	int mismatchCount = handleObstacles(initalPoint, obstacles);

	return mismatchCount;
}

int Map::update(double x, double y, double yaw, const Laser& laser)
{
	// Handle new Obstacles
	vector<Point> obstacles;
	laser.getObstacles(x, y, yaw, obstacles);

	Point initalPoint(x, y);
	int mismatchCount = handleObstacles(initalPoint, obstacles);

	return mismatchCount;
}
