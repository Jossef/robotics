/*
 * Point.h
 *
 *  Created on: May 27, 2014
 *      Author: user
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

// ----------------------------------
// GENERAL

#define DEMO_MODE false
#define DEMO_RANDOM 100
#define DEMO_RANDOM_RATIO 100

// ----------------------------------
// Laser Configuration

#define LASER_RESOLUTION 0.36
#define LASER_MESURING_AREA 120
#define LASER_MAXIMUM_RANGE 2
#define LASER_ARRAY_SIZE 666

#define LASER_OBSTACLE_DISTANCE 1.0

#define LASER_MIN_ROTATION_DISTANCE 0.25

#define LASER_MIN_FORWARD_DISTANCE 0.5
#define LASER_MIN_FORWARD_START_INDEX 233
#define LASER_MIN_FORWARD_END_INDEX 413

// ----------------------------------
// Map

#define MAP_ROWS 10
#define MAP_COLUMNS 10
#define MAP_RESOLUTION 0.1
#define MAP_INTERMEDIATE_POINT_DISTANCE 0.5

// ----------------------------------
// Particle

#define PARTICLE_ERROR_RANGE 5
#define PARTICLE_MAGIC_NUMBER 5

#define PARTICLE_KILL_BELIEF 0.3
#define PARTICLE_CHILEDS_COUNT 5

#endif /* POINT_H_ */
