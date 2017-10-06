// Include header file
#include "parsing.h"

// < 0 == error, but > 0 the return value is the number of objects
int parseInput(camera_t *camera, object_t **scene, FILE *file) {

  int numObjects = 0;

  // TODO: Remove this when CSV parsing is set up
  // Create test scene
  // This breaks when the z position is "greater" than the radius
  /*sphere->position = vector3_create(0, 0, -51);
  sphere->radius = 50;*/

  camera->kind = OBJECT_KIND_CAMERA;
  camera->width = 0.5;
  camera->height = 0.5;

  // Test Sphere
  sphere_t *sphere = malloc(sizeof(sphere_t));
  sphere->kind = OBJECT_KIND_SPHERE;
  sphere->color = vector3_create(0.1, 0.5, 0.2);
  sphere->position = vector3_create(0, 0, -60);
  sphere->radius = 5;
  scene[0] = (object_t *) sphere;

  // Test Plane
  plane_t *plane = malloc(sizeof(plane_t));
  plane->kind = OBJECT_KIND_PLANE;
  plane->color = vector3_create(0.6, 0.5, 0.2);
  plane->position = vector3_create(0, 0, -57);
  plane->normal = vector3_create(0, 0, 1);
  scene[1] = (object_t *) plane;

  numObjects = 2;


  // TODO: Implement actual input parsing
  /*char line[MAX_LINE_LENGTH];

  while (fgets(line, MAX_LINE_LENGTH, file)) {

    printf("%s", line);

    char* token = strtok(line, "c");
    while (token) {

      printf("%s\n", token);

      token = strtok(0, ",");
    }
  }*/

  return numObjects;
}
