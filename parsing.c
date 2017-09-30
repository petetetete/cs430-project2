// Include header file
#include "parsing.h"

int parseInput(object_t *scene, FILE *file) {

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

  return 0;
}

/*void asdf(object_t *input) {

  sphere_t *sphere = (sphere_t *) input;
  printf("%d\n", sphere->kind);
  printf("%.2f\n", sphere->radius);
}*/

/*int main(int argc, char *argv[]) {

  object_t *test = malloc(sizeof(object_t));
  sphere_t *sphere = malloc(sizeof(sphere_t));

  test->kind = OBJECT_KIND_CAMERA;
  sphere->kind = OBJECT_KIND_SPHERE;
  sphere->radius = 6.5;

  object_t *scene = malloc(sizeof(object_t) * 10);

  scene[0] = *test;
  scene[1] = *(object_t*) sphere;

  object_t *convert = (object_t *) sphere;
  sphere_t *sphere2 = (sphere_t *) convert;
  object_t *back = (object_t *) sphere2;

  asdf(back);

  return 0;
}
*/