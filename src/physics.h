#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>
#include "vector.h"

typedef struct {
    vec2_t pos;
    vec2_t size;
} aabb_t;

static inline void aabb_max_pos(vec2_t *const out, const aabb_t *const box) {
    out->x = box->pos.x + box->size.x;
    out->y = box->pos.y + box->size.y;
}

static inline void aabb_center(vec2_t *const out, const aabb_t *const box) {
    out->x = box->pos.x + box->size.x / 2;
    out->y = box->pos.y + box->size.y / 2;
}

typedef struct {
    vec2_t pos;
    float radius;
} circle_t;

typedef struct {
    vec2_t pos;
    vec2_t *vertex_offsets;
    size_t vertex_offsets_length;
} polygon_t;

bool phys_point_inside_aabb(const aabb_t *const aabb, const vec2_t *const point);
bool phys_point_inside_circle(const circle_t *const circle, const vec2_t *const point);
bool phys_poly_inside_poly(const polygon_t *const first, const polygon_t *const second);

typedef struct {
    circle_t characters[8];
} phys_t;

#endif
