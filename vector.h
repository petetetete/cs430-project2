#ifndef VECTOR_H
#define VECTOR_H

// Include standard libraries
#include <stdlib.h>
#include <math.h>

// Define types to be used in c file
typedef double* vector3_t;


static inline void vector3_add(vector3_t c, vector3_t a, vector3_t b);

static inline void vector3_sub(vector3_t c, vector3_t a, vector3_t b);

static inline void vector3_scale(vector3_t c, vector3_t a, double b);

static inline double vector3_dot(vector3_t a, vector3_t b);

static inline void vector3_cross(vector3_t c, vector3_t a, vector3_t b);

vector3_t vector3_create(double a, double b, double c);

vector3_t vector3_createUnit(double a, double b, double c);


#endif  // VECTOR_H
