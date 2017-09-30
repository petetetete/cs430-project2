// Include header file
#include "raycast.h"

vector3_t raycast(object_t **scene, int numObjects) {

  // Test
  vector3_t color = vector3_create(0.6, 0.3, 0.4);

  // TODO: Determine accurate color

  return color;
}

// Actually creates and initializes the image
int renderImage(ppm_t *ppmImage, object_t **scene, int numObjects) {

  // Iterate over every pixel in the would be image
  for (int i = 0; i < ppmImage->width; i++) {
    for (int j = 0; j < ppmImage->height; j++) {

      vector3_t color = raycast(scene, numObjects);

      // Populate pixel with color data
      ppmImage->pixels[i*ppmImage->height + j].r = (int) (color[0] * 255);
      ppmImage->pixels[i*ppmImage->height + j].g = (int) (color[1] * 255);
      ppmImage->pixels[i*ppmImage->height + j].b = (int) (color[2] * 255);
    }
  }

  // No errors!
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

  if (viewWidth <= 0 || viewHeight <= 0) {
    fprintf(stderr, "Error: Invalid width or height, must be > 0\n");
    return 1;
  }

  // Initialize variables to be used in program
  FILE *inputFH;
  FILE *outputFH;
  object_t **scene = malloc(sizeof(object_t) * MAX_SCENE_OBJECTS);
  int numObjects;

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

  // Parse input csv into scene object
  numObjects = parseInput(scene, inputFH);

  // Handle errors found in parseInput
  if (numObjects < 0) {
    fprintf(stderr, "Error: Malformed input CSV\n", outputFName);
    return 1;
  }

  // Create actual PPM image from scene
  renderImage(ppmImage, scene, numObjects);

  // Handle open errors on output file
  if (!(outputFH = fopen(outputFName, "w"))) {
    fprintf(stderr, "Error: Unable to open '%s' for writing\n", outputFName);
    return 1;
  }

  // Write final raycasted product to the designated PPM file
  writePPM(ppmImage, outputFH, 3);

  // Clean up program
  fclose(inputFH);

  return 0;
}
