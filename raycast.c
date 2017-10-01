// Include header file
#include "raycast.h"

double sphereIntersection(vector3_t direction, sphere_t* sphere) {

  vector3_t position = sphere->position;

  double a = direction[0]*direction[0] +
             direction[1]*direction[1] +
             direction[2]*direction[2];

  double b = -2*(position[0]*direction[0] +
                 position[1]*direction[1] +
                 position[2]*direction[2]);

  double c = position[0]*position[0] +
             position[1]*position[1] +
             position[2]*position[2] -
             sphere->radius*sphere->radius;

  double discr = b*b - 4*a*c;

  // TODO: Figure out what's up with the discriminant here
  printf("direction vector: %.3f %.3f %.3f\n", direction[0], direction[1], direction[2]);
  printf("object position: %.3f %.3f %.3f\n", position[0], position[1], position[2]);
  printf("a: %.3f, b: %.3f, c: %.3f\n", a, b, c);
  printf("discriminant: %.3f\n\n", discr);

  if (discr < 0) {
    return NO_INTERSECTION_FOUND;
  }
  else {
    // TODO: Check if both of these are necessary
    double t1 = (-b + sqrt(discr)) / (2*a);
    double t2 = (-b - sqrt(discr)) / (2*a);

    printf("t1: %.3f,  t2: %.3f\n", t1, t2);
    if (t1 < t2) {
      return t1;
    }
    else {
      return t2;
    }
  }
}

double planeIntersection(vector3_t direction, plane_t* plane) {

  // TODO

  return 0;
}

vector3_t raycast(object_t **scene, vector3_t direction, int numObjects) {

  // Track closet object
  vector3_t closestColor = vector3_create(0, 0, 0); // Default to black
  double closestT = INFINITY;

  // Iterate through all objects to find nearest color
  for (int i = 0; i < numObjects; i++) {

    // Current object and t value
    object_t *object = scene[i];
    vector3_t color;
    double t;

    // Determine which intersection type to check for
    if (object->kind == OBJECT_KIND_SPHERE) {
      sphere_t *sphere = (sphere_t *) object; // Convert to sphere
      color = sphere->color;
      t = sphereIntersection(direction, sphere);
    }
    else if (object->kind == OBJECT_KIND_PLANE) {
      plane_t *plane = (plane_t *) object; // Convert to plane
      color = plane->color;
      t = planeIntersection(direction, plane);
    }

    // If the current t was closer than all before, save the color
    if (t != NO_INTERSECTION_FOUND && t < closestT) {
      closestT = t;
      closestColor = color;
    }
  }

  return closestColor;
}

// Actually creates and initializes the image
int renderImage(ppm_t *ppmImage, object_t **scene, int numObjects) {

  // Iterate over every pixel in the would be image
  for (int i = 0; i < ppmImage->width; i++) {
    for (int j = 0; j < ppmImage->height; j++) {

      vector3_t direction = vector3_createUnit(
        -VIEW_PLANE_WIDTH/2 + (VIEW_PLANE_WIDTH/ppmImage->width) * (i + 0.5),
        VIEW_PLANE_HEIGHT/2 - (VIEW_PLANE_HEIGHT/ppmImage->height) * (j + 0.5),
        -FOCAL_LENGTH);

      vector3_t color = raycast(scene, direction, numObjects);

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
  sphere->color = vector3_create(0.1, 0.5, 0.2);
  sphere->position = vector3_create(0, 0, -50);
  sphere->radius = 20;
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
