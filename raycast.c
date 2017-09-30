// Include header file
#include "raycast.h"

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

  // Initialize variables to be used in program
  FILE *inputFH;
  FILE *outputFH;
  object_t *scene = malloc(sizeof(object_t) * MAX_SCENE_OBJECTS);

  // Handle input file errors
  if (!(inputFH = fopen(inputFName, "r"))) {
    fprintf(stderr, "Error: Input file '%s' could not be found\n", inputFName);
    return 1;
  }

  // Parse input csv into scene object
  parseInput(scene, inputFH);

  // Clean up program
  fclose(inputFH);

}
