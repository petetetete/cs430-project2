#ifndef RAYCAST_H
#define RAYCAST_H

// Include standard libraries
#include <stdlib.h>
#include <stdio.h>
#include "ppmrw.h"
#include "vector.h"
#include "parsing.h"

// Numeric constants
#define MAX_SCENE_OBJECTS 128

// String constants
#define USAGE_MESSAGE "\
Usage: raycast width height input_file output.ppm\n\
  width: pixel width of the view plane\n\
  height: pixel height of the view plane\n\
  input_file: csv file of scene objects\n\
  output_file: final out PPM file name\n"



vector3_t raycast(object_t **scene, int numObjects);

int renderImage(ppm_t *ppmImage, object_t **scene, int numObjects);


#endif  // RAYCAST_H
