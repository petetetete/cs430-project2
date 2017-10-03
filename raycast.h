#ifndef RAYCAST_H
#define RAYCAST_H

// Include standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ppmrw.h"
#include "vector.h"
#include "parsing.h"

// Error code constants
#define NO_INTERSECTION_FOUND -2

// Numeric constants
#define MAX_SCENE_OBJECTS 128
#define VIEW_PLANE_WIDTH 100 // In world units
#define VIEW_PLANE_HEIGHT 100 // In world units
#define FOCAL_LENGTH 1 // In world units

// String constants
#define USAGE_MESSAGE "\
Usage: raycast width height input_file output.ppm\n\
  width: pixel width of the view plane\n\
  height: pixel height of the view plane\n\
  input_file: csv file of scene objects\n\
  output_file: final out PPM file name\n"


double sphereIntersection(vector3_t direction, sphere_t* sphere);

double planeIntersection(vector3_t direction, plane_t* plane);

vector3_t raycast(object_t **scene, vector3_t direction, int numObjects);

int renderImage(ppm_t *ppmImage, object_t **scene, int numObjects);


#endif  // RAYCAST_H
