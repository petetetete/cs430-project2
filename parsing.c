// Include header file
#include "parsing.h"

// < 0 == error, but > 0 the return value is the number of objects
int parseInput(object_t **scene, FILE *file) {

  int numObjects;

  // TODO: Remove this when CSV parsing is set up
  // Create test scene
  // This breaks when the z position is "greater" than the radius
  /*sphere->position = vector3_create(0, 0, -51);
  sphere->radius = 50;*/

  // Test Sphere
  sphere_t *sphere = malloc(sizeof(sphere_t));
  sphere->kind = OBJECT_KIND_SPHERE;
  sphere->color = vector3_create(0.1, 0.5, 0.2);
  sphere->position = vector3_create(2.0, 2.0, -50.1);
  sphere->radius = 50.05;
  scene[0] = (object_t *) sphere;

  // Test Plane
  /*plane_t *plane = malloc(sizeof(plane_t));
  plane->kind = OBJECT_KIND_PLANE;
  plane->color = vector3_create(0.1, 0.5, 0.2);
  plane->position = vector3_create(0, 0, -50);
  plane->normal = vector3_create(1, 0.2, 0.1);
  scene[0] = (object_t *) plane;*/

  numObjects = 1;


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
