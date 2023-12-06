#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <gmath.h>

typedef struct {
    float x;
    float y;
} vec2_t;

#define VEC(X, Y) ((vec2_t) { .x = (X), .y = (Y) })

static inline void vec2_mult(vec2_t *const vec, const float by) {
    vec->x *= by;
    vec->y *= by;
}

static inline void vec2_add(vec2_t *const vec, const vec2_t *const with) {
    vec->x += with->x;
    vec->y += with->y;
}

static inline float vec2_dot(const vec2_t *const first, const vec2_t *const second) {
    return first->x * second->x + first->y * second->y;
}

static inline float vec2_sqrmag(const vec2_t *const vec) {
    return vec->x * vec->x + vec->y * vec->y;
}

static inline float vec2_mag(const vec2_t *const vec) {
    return sqrtf(vec2_sqrmag(vec));
}

static inline float vec2_invmag(const vec2_t *const vec) {
    return g_rsqrt(vec2_sqrmag(vec));
}

static inline void vec2_normalize(vec2_t *const vec) {
    vec2_mult(vec, vec2_invmag(vec));
}

#endif
