#ifndef PARSING_H
#define PARSING_H

// Include standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

// Define constants
#define OBJECT_KIND_CAMERA 1
#define OBJECT_KIND_SPHERE 2
#define OBJECT_KIND_PLANE 3

// Numeric constants
#define MAX_LINE_LENGTH 256

// Define types to be used in c file
typedef struct object_t object_t;
typedef struct camera_t camera_t;
typedef struct sphere_t sphere_t;
typedef struct plane_t plane_t;

struct object_t {
  int kind;
};

struct camera_t {
  struct object_t;
  double width;
  double height;
};

struct sphere_t {
  struct object_t;
  vector3_t color;
  vector3_t position;
  double radius;
};

struct plane_t {
  struct object_t;
  vector3_t color;
  vector3_t position;
  vector3_t normal;
};


int parseInput(object_t **scene, FILE *file);

#endif  // PARSING_H
