#include "stdafx.h"
#include "PointDistance.h"

	vector<pair<float,float>> PointDistance::GetDistancePoints(pair<float,float> pRobotLoc, pair<float,float> pObstacleLoc, float fDist)
	{
		vector<pair<float,float>> arrpntPoints;

		float deltaY = max(pObstacleLoc.second,pRobotLoc.second) - min(pRobotLoc.second,pObstacleLoc.second);
		float deltaX = max(pObstacleLoc.first,pRobotLoc.first) - min(pRobotLoc.first,pObstacleLoc.first);

		float angleInDegrees = atan(deltaY / deltaX) * (180 / M_PI);

		float angleInRadians = angleInDegrees * (M_PI/180);

		float fXDist = fDist * cos(angleInRadians);
		float fYDist = fDist * sin(angleInRadians);

		pair<float,float> pPoint1;
		pair<float,float> pPoint2;

		if (pRobotLoc.first <= pObstacleLoc.first)
		{
			pPoint1.first = pRobotLoc.first;
			pPoint1.second = pRobotLoc.second;
			pPoint2.first = pObstacleLoc.first;
			pPoint2.second = pObstacleLoc.second;
		}
		else
		{
			pPoint1.first = pObstacleLoc.first;
			pPoint1.second = pObstacleLoc.second;
			pPoint2.first = pRobotLoc.first;
			pPoint2.second = pRobotLoc.second;
		}

		if (pPoint1.second <= pPoint2.second)
		{
			while (pPoint1.first + fXDist <= pPoint2.first && pPoint1.second + fYDist <= pPoint2.second)
			{
				pair<float,float> pTempPoint;
				pTempPoint.first = pPoint1.first + fXDist;
				pTempPoint.second = pPoint1.second + fYDist;

				arrpntPoints.push_back(pTempPoint);

				pPoint1.first += fXDist;
				pPoint1.second += fYDist;
			}
		}
		else
		{
			while (pPoint1.first + fXDist <= pPoint2.first && pPoint1.second - fYDist >= pPoint2.second)
			{
				pair<float,float> pTempPoint;
				pTempPoint.first = pPoint1.first + fXDist;
				pTempPoint.second = pPoint1.second - fYDist;

				arrpntPoints.push_back(pTempPoint);

				pPoint1.first += fXDist;
				pPoint1.second -= fYDist;
			}
		}

		return (arrpntPoints);
	}
