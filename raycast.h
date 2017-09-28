#ifndef RAYCAST_H
#define RAYCAST_H

// Include standard libraries
#include <stdlib.h>
#include <stdio.h>

// Define constants
#define OBJECT_KIND_CAMERA 1
#define OBJECT_KIND_SPHERE 2
#define OBJECT_KIND_PLANE 3

// Define types to be used in c file
typedef struct Object Object;
typedef struct Camera Camera;
typedef struct Sphere Sphere;
typedef struct Plane Plane;

struct Object {
  int kind;
};

struct Camera {
  struct Object;
  double width;
  double height;
};

struct Sphere {
  struct Object;
  double color[3];
  double position[3];
  double radius;
};

struct Plane {
  struct Object;
  double color[3];
  double position[3];
  double normal[3];
};

#endif  // RAYCAST_H
