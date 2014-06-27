/*
 * Point.h
 *
 *  Created on: May 27, 2014
 *      Author: user
 */

#ifndef POINT_H_
#define POINT_H_

#include "pair.h"

using namespace std;

class Point : public pair<double,double>
{
public:
	Point()
	{

	}

	Point(double first, double second) : pair<double,double>(first, second)
	{
	}

	virtual ~Point()
	{

	}
};

#endif /* POINT_H_ */
