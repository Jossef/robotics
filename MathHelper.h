#ifndef MathHelper_H_
#define MathHelper_H_

#include <vector>
#include <pair.h>
#include <math.h>
#include "Point.h"

using namespace std;

class MathHelper
{

public:
	static void GetIntermediatePoints(const Point& firstPoint, const Point& secondPoint, double measuringDistance, vector<Point>& intermediatePoints);

	static double ConvertDegreeToRadian(double degree);

	static double ConvertRadianToDegree(double radian);
	
	static pair<double,double> GetIndexFromRadius(double dDistanceRadius, double dRobotWidth);
};

#endif // MathHelper_H_
