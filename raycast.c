// Include header file
#include "raycast.h"

int main(int argc, char *argv[]) {

  object_t *test = malloc(sizeof(object_t));
  sphere_t *sphere = malloc(sizeof(sphere_t));

  test->kind = OBJECT_KIND_SPHERE;
  sphere->kind = OBJECT_KIND_SPHERE;

  printf("%d", sphere->kind);

  return 0;
}
