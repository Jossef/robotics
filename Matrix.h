/*
 * Matrix.h
 *
 *  Created on: Apr 22, 2014
 *      Author: user
 */

#ifndef Matrix_H_
#define Matrix_H_

#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
class Matrix
{
	std::vector<T> _vector;
	unsigned int _dimx;
	unsigned int _dimy;

public:

	Matrix()
	{
	}

	void init(unsigned int dimx, unsigned int dimy, const T initValue)
	{
		_dimx = dimx;
		_dimy = dimy;
		_vector.resize(_dimx * _dimy);
		std::fill(_vector.begin(), _vector.end(), initValue);
	}

	T& operator()(unsigned int x, unsigned int y)
	{
		if (x >= _dimx || y >= _dimy)
		{
			ostringstream message;
			message << "got x: " << x << ", got y: " << y << ", dim x: " << _dimx << ", dim y: " << _dimy;
			throw invalid_argument(message.str());
		}

		int offset = (_dimx * y) + x;
		return _vector[offset];
	}

	T operator()(unsigned int x, unsigned int y) const
	{
		if (x >= _dimx || y >= _dimy)
		{
			ostringstream message;
			message << "got x: " << x << ", got y: " << y << ", dim x: " << _dimx << ", dim y: " << _dimy;
			throw invalid_argument(message.str());
		}

		int offset = (_dimx * y) + x;
		return _vector[offset];
	}

	virtual ~Matrix()
	{

	}
};

#endif /* Matrix_H_ */
