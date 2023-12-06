#ifndef DRAW_H
#define DRAW_H

#include <debug.h>
#include "vector.h"

extern vec2_t draw_cam_pos;

void draw_line(const vec2_t *const pos1, const vec2_t *const pos2);
void draw_polygon_outline(const vec2_t *const points, const size_t length);

#ifndef NDEBUG
#define dbg_draw_line(pos1, pos2) (draw_line(pos1, pos2))
#define dbg_draw_polygon_outline(points, length) (draw_polygon_outline(points, length))
#else
#define dbg_draw_line(pos1, pos2) ((void)0)
#define dbg_draw_polygon_outline(points, length) ((void)0)
#endif

#endif