#include <stdbool.h>
#include <float.h>
#include "vector.h"
#include "physics.h"

static void calculate_edge_normal(const vec2_t *const first, const vec2_t *const second, vec2_t *const out) {
    vec2_t edge = *first;
    vec2_subtract(&edge, second);
    edge = VEC(edge.y, edge.x);
    vec2_normalize(&edge);
    *out = edge;
}

static bool check_edge(const vec2_t *const vert1, const vec2_t *const vert2, const polygon_t *const first, const polygon_t *const second) {
    vec2_t normal;
    calculate_edge_normal(vert1, vert2, &normal);

    // balls allighnted balls boxes

    float first_min, first_max, second_min, second_max;
    first_min = second_min = FLT_MAX;
    first_max = second_max = -FLT_MAX;

    for (size_t i = 0; i < first->vertex_offsets_length; i++) {
        float dot = vec2_dot(first->vertex_offsets + i, &normal);
        if (dot < first_min) first_min = dot;
        if (dot > first_max) first_max = dot;
    }

    for (size_t i = 0; i < second->vertex_offsets_length; i++) {
        float dot = vec2_dot(second->vertex_offsets + i, &normal);
        if (dot < second_min) second_min = dot;
        if (dot > second_max) second_max = dot;
    }

    return second_min <= first_max && first_min <= second_max;
}

bool phys_poly_inside_poly(const polygon_t *const first, const polygon_t *const second) {
    for (size_t i = 0; i < first->vertex_offsets_length; i++) {
        vec2_t vert1 = first->vertex_offsets[i];
        vec2_t vert2 = first->vertex_offsets[(i + 1) % first->vertex_offsets_length];
        if (!check_edge(&vert1, &vert2, first, second))
            return false;
    }
    for (size_t i = 0; i < second->vertex_offsets_length; i++) {
        vec2_t vert1 = second->vertex_offsets[i];
        vec2_t vert2 = second->vertex_offsets[(i + 1) % second->vertex_offsets_length];
        if (!check_edge(&vert1, &vert2, first, second))
            return false;
    }

    return true;
}
