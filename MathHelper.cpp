#include "MathHelper.h"

void MathHelper::GetIntermediatePoints(const Point& firstPoint, const Point& secondPoint, double measuringDistance, vector<Point >& intermediatePoints)
{
	double deltaY = max(secondPoint.second, firstPoint.second) - min(firstPoint.second, secondPoint.second);
	double deltaX = max(secondPoint.first, firstPoint.first) - min(firstPoint.first, secondPoint.first);

	// TODO check if this Radian conversion is necessary
	double angleInDegrees = atan(deltaY / deltaX) * (180 / M_PI);
	double angleInRadians = angleInDegrees * (M_PI / 180);

	double measuringDistanceX = measuringDistance * cos(angleInRadians);
	double measuringDistanceY = measuringDistance * sin(angleInRadians);

	Point startPoint;
	Point endPoint;

	if (firstPoint.first <= secondPoint.first)
	{
		startPoint.first = firstPoint.first;
		startPoint.second = firstPoint.second;
		endPoint.first = secondPoint.first;
		endPoint.second = secondPoint.second;
	}
	else
	{
		startPoint.first = secondPoint.first;
		startPoint.second = secondPoint.second;
		endPoint.first = firstPoint.first;
		endPoint.second = firstPoint.second;
	}

	if (startPoint.second <= endPoint.second)
	{
		while (startPoint.first + measuringDistanceX <= endPoint.first && startPoint.second + measuringDistanceY <= endPoint.second)
		{
			Point tempPoint;
			tempPoint.first = startPoint.first + measuringDistanceX;
			tempPoint.second = startPoint.second + measuringDistanceY;

			intermediatePoints.push_back(tempPoint);

			startPoint.first += measuringDistanceX;
			startPoint.second += measuringDistanceY;
		}
	}
	else
	{
		while (startPoint.first + measuringDistanceX <= endPoint.first && startPoint.second - measuringDistanceY >= endPoint.second)
		{
			Point tempPoint;
			tempPoint.first = startPoint.first + measuringDistanceX;
			tempPoint.second = startPoint.second - measuringDistanceY;

			intermediatePoints.push_back(tempPoint);

			startPoint.first += measuringDistanceX;
			startPoint.second -= measuringDistanceY;
		}
	}
}


double MathHelper::ConvertDegreeToRadian(double degree)
{
	return degree * M_PI / 180.0;

}
double MathHelper::ConvertRadianToDegree(double radian)
{
	return radian * 180.0 / M_PI;

}
