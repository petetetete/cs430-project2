#ifndef VECTOR_H
#define VECTOR_H

// Include standard libraries
#include <stdlib.h>

// Define types to be used in c file
typedef double* vector3_t;


static inline void vector3_add(vector3_t c, vector3_t a, vector3_t b);

static inline void vector3_sub(vector3_t c, vector3_t a, vector3_t b);

static inline void vector3_scale(vector3_t c, vector3_t a, double b);

static inline double vector3_dot(vector3_t a, vector3_t b);

static inline void vector3_cross(vector3_t c, vector3_t a, vector3_t b);


#endif  // VECTOR_H
