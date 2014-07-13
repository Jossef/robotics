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

pair<double,double> MathHelper::GetIndexFromRadius(double dDistanceRadius, double dRobotWidth)
{
	// Getting half of width
	double dHalfWidth = dRobotWidth / 2;

	// Getting X and Y points that intersect the circle radius
	// http://mathworld.wolfram.com/Circle-LineIntersection.html

	// Getting 2 points of the vertical line
	Point pntLineFirstPoint(dHalfWidth,0);

	Point pntLineSecondPoint(dHalfWidth, dDistanceRadius * 2);

	// Getting intersection with radius
	double dX = pntLineSecondPoint.getX() - pntLineFirstPoint.getX();
	double dY = pntLineSecondPoint.getY() - pntLineFirstPoint.getY();

	double dR = sqrt(pow(dX,2) + pow(dY,2));

	double D = (pntLineFirstPoint.getX() *  pntLineSecondPoint.getY()) - (pntLineSecondPoint.getX() * pntLineFirstPoint.getY());

	double dXIntersect = (D * dY + dX * sqrt(pow(dDistanceRadius,2) * pow(dR,2) - pow(D,2))) / pow(dR,2);
	double dYIntersect = (-D * dX + dY * sqrt(pow(dDistanceRadius,2) * pow(dR,2) - pow(D,2))) / pow(dR,2);

	// Calculating angle
	// http://stackoverflow.com/a/1211243

	// Positive X
	Point P1(0,0);
	Point P2(dXIntersect, dYIntersect);
	Point P3(pntLineFirstPoint.getX(), pntLineFirstPoint.getY());

	double P12 = sqrt(pow(P2.getX()-P1.getX(),2) + pow(P2.getY()-P1.getY(),2));
	double P23 = sqrt(pow(P3.getX()-P2.getX(),2) + pow(P3.getY()-P2.getY(),2));
	double P13 = sqrt(pow(P1.getX()-P3.getX(),2) + pow(P1.getY()-P3.getY(),2));

	double dPositiveAngle = acos((pow(P12,2)+pow(P13,2)-pow(P23,2)) / (2 *P12 * P13));

	// Negative X
	double dNegativeAngle = -dPositiveAngle;

	pair<double,double> Angles;
	Angles = make_pair(dPositiveAngle, dNegativeAngle);

	return Angles;
}
