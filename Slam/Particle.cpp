#include "Particle.h"

Particle::Particle() :
	_map()
{
	_belief = 0.9;
	_x = 0;
	_y = 0;
	_yaw = 0;
}

double Particle::probabilityMove(double deltaX, double deltaY, double deltaYaw)
{
	double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	double absoluteYaw = abs(deltaYaw);

	if ((absoluteYaw == 0) && (distance < PARTICLE_PROB_MOV_DISTANCE))
	{
		return 1;
	}
	else if ((distance < PARTICLE_PROB_MOV_DISTANCE) && (absoluteYaw < PARTICLE_PROB_MOV_YAW))
	{
		return 0.8;
	}
	else if (((distance > PARTICLE_PROB_MOV_DISTANCE) && (absoluteYaw < PARTICLE_PROB_MOV_YAW)) ||
			 ((distance < PARTICLE_PROB_MOV_DISTANCE) && (absoluteYaw > PARTICLE_PROB_MOV_YAW)))
	{
		return 0.6;
	}

	return 0.2;
}

void Particle::move(double deltaX, double deltaY, double deltaYaw)
{
	_x += deltaX;
	_y += deltaY;
	_yaw += deltaYaw;
}

double Particle::update(double deltaX, double deltaY, double deltaYaw, const Laser& laser)
{
	// ---------------
	// Update Particle x, y, yaw
	move(deltaX, deltaY, deltaYaw);

	double probability = probabilityMove(deltaX, deltaY, deltaYaw);
	double previewsBelief = _belief * probability;

	// ---------------
	// Update Map

	double matchPercent;
	try
	{
		matchPercent = _map.update(_x, _y, _yaw, laser);
	}
	catch (...)
	{
		matchPercent=0;
	}

	// ---------------
	// Update Belief
	//cout << (PARTICLE_MAGIC_NUMBER * previewsBelief * matchPercent) << "= "<< PARTICLE_MAGIC_NUMBER << "*" << _belief << "*" << probability << "*" << matchPercent << '\n';
	_belief = PARTICLE_MAGIC_NUMBER * previewsBelief * matchPercent;

	if (_belief > 1) _belief=1;

	return _belief;
}

Particle Particle::create()
{
	Particle newPar;
	//initialize random seed
	srand(time(NULL));

	newPar._x = _x + rand() % PARTICLE_ERROR_RANGE;
	newPar._y = _y + rand() % PARTICLE_ERROR_RANGE;
	newPar._yaw = _yaw + rand() % PARTICLE_ERROR_RANGE;

	// Next generation gets a copy of my current map
	// This is done by copy constructor
	newPar._map = _map;

	return newPar;
}
Map& Particle::getMap()
{
	return _map;
}
bool Particle::operator ==(const Particle& ref)
{
	if (_x == ref._x &&
		_y == ref._y &&
		_yaw == ref._yaw &&
		_belief == ref._belief)
	{
		return true;
	}

	return false;
}

double Particle::getBelief() const
{
	return _belief;
}
