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
	static void GetIntermediatePoints(Point firstPoint, Point secondPoint, double measuringDistance, vector<Point >& intermediatePoints);

	static double ConvertDegreeToRadian(double degree);

	static double ConvertRadianToDegree(double radian);
};

#endif // MathHelper_H_
