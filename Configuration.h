/*
 * Point.h
 *
 *  Created on: May 27, 2014
 *      Author: user
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

// ----------------------------------
// Laser Configuration

#define LASER_RESOLUTION 0.36
#define LASER_MESURING_AREA 120
#define LASER_MAXIMUM_RANGE 2
#define LASER_ARRAY_SIZE 666

// ----------------------------------
// Playables

#define LASER_OBSTACLE_DISTANCE 1.0

#define LASER_MIN_ROTATION_DISTANCE 0.3
#define LASER_MIN_FORWARD_DISTANCE 0.7

#define LASER_MIN_FORWARD_START_INDEX 253
#define LASER_MIN_FORWARD_END_INDEX  403

// ----------------------------------
// Map

#define MAP_ROWS 10
#define MAP_COLUMNS 10
#define MAP_RESOLUTION 0.1

#define MAP_INTERMEDIATE_POINT_DISTANCE 1.0

#endif /* POINT_H_ */
