// Include header file
#include "raycast.h"

// Actually creates and initializes the image
int renderImage(ppm_t *ppmImage, object_t **scene) {

  // Tests
  /*printf("%d\n", scene[0]->kind);
  sphere_t *asdf = (sphere_t *) scene[0];
  printf("%.3f", asdf->radius);*/

  // Iterate over every pixel in the would be image
  for (int i = 0; i < ppmImage->width; i++) {
    for (int j = 0; j < ppmImage->height; j++) {

    }
  }

  return 0;
}

int main(int argc, char *argv[]) {

  // Check for the appropriate number of parameters
  if (argc != 5) {
    fprintf(stderr, USAGE_MESSAGE);
    return 1;
  }

  // Save command line parameters
  int viewWidth = atoi(argv[1]);
  int viewHeight = atoi(argv[2]);
  char *inputFName = argv[3];
  char *outputFName = argv[4];

  // TODO: Validate actual input

  // Initialize variables to be used in program
  FILE *inputFH;
  FILE *outputFH;
  object_t **scene = malloc(sizeof(object_t) * MAX_SCENE_OBJECTS);

  // Create final ppmImage
  ppm_t *ppmImage = malloc(sizeof(ppm_t));
  ppmImage->width = viewWidth;
  ppmImage->height = viewHeight;
  ppmImage->maxColorValue = 255;
  ppmImage->pixels = malloc(sizeof(pixel_t)*ppmImage->width*ppmImage->height);

  // TODO: Remove this when CSV parsing is set up
  // Create test scene
  sphere_t *sphere = malloc(sizeof(sphere_t));
  sphere->kind = OBJECT_KIND_SPHERE;
  sphere->color = vector3_create(0, 0, 0);
  sphere->position = vector3_create(0, 0, -20);
  sphere->radius = 7.0;

  scene[0] = (object_t *) sphere;

  // Handle input file errors
  if (!(inputFH = fopen(inputFName, "r"))) {
    fprintf(stderr, "Error: Input file '%s' could not be found\n", inputFName);
    return 1;
  }

  // TODO: Actually use this
  // Parse input csv into scene object
  // parseInput(scene, inputFH);

  // Create actual PPM image from scene
  renderImage(ppmImage, scene);

  // Clean up program
  fclose(inputFH);

}
