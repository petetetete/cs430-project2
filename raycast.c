// Include header file
#include "raycast.h"

int main(int argc, char *argv[]) {

  Object *test = malloc(sizeof(Object));
  Sphere *sphere = malloc(sizeof(Sphere));

  test->kind = OBJECT_KIND_SPHERE;
  sphere->kind = OBJECT_KIND_SPHERE;

  printf("%d", sphere->kind);

  return 0;
}
