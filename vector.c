// Include header file
#include "vector.h"

static inline void vector3_add(vector3_t c, vector3_t a, vector3_t b) {
  c[0] = a[0] + b[0];
  c[1] = a[1] + b[1];
  c[2] = a[2] + b[2];
}

static inline void vector3_sub(vector3_t c, vector3_t a, vector3_t b) {
  c[0] = a[0] - b[0];
  c[1] = a[1] - b[1];
  c[2] = a[2] - b[2];
}

static inline void vector3_scale(vector3_t c, vector3_t a, double b) {
  c[0] = a[0] * b;
  c[1] = a[1] * b;
  c[2] = a[2] * b;
}

static inline double vector3_dot(vector3_t a, vector3_t b) {
  return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

static inline void vector3_cross(vector3_t c, vector3_t a, vector3_t b) {
  c[0] = a[1]*b[2] - a[2]*b[1];
  c[1] = a[2]*b[0] - a[0]*b[2];
  c[2] = a[0]*b[1] - a[1]*b[0];
}
