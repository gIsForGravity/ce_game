#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include "vector.h"

typedef struct {
    vec2_t min_pos;
    vec2_t size;
} aabb_t;

static inline void aabb_max_pos(vec2_t *const out, const aabb_t *const box) {
    out->x = box->min_pos.x + box->size.x;
    out->y = box->min_pos.y + box->size.y;
}

typedef struct {
    vec2_t pos;
    float radius;
} circle_t;

bool phys_point_inside_aabb(const aabb_t *const aabb, const vec2_t *const point);
bool phys_point_inside_circle(const circle_t *const circle, const vec2_t *const point);

typedef struct {
    circle_t characters[8];
} phys_t;

#endif
