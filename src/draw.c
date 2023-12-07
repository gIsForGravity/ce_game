#include <graphx.h>
#include "vector.h"
#include "draw.h"

vec2_t draw_cam_pos = {0};

static inline void convert_pos(vec2_t *const pos) {
    pos->y = -(pos->y - draw_cam_pos.y) + (GFX_LCD_HEIGHT / 2);
    pos->x = (pos->x - draw_cam_pos.x) + (GFX_LCD_WIDTH / 2);
}

void draw_line(const vec2_t *const pos1, const vec2_t *const pos2) {
    vec2_t newpos1 = *pos1;
    vec2_t newpos2 = *pos2;
    convert_pos(&newpos1);
    convert_pos(&newpos2);
    gfx_Line(newpos1.x, newpos1.y, newpos2.x, newpos2.y);
};

void draw_polygon_outline_at(const vec2_t *const points, const size_t length, const vec2_t *const pos) {
    for (size_t i = 0; i < length; i++) {
        vec2_t first = points[i];
        vec2_t second = points[(i + 1) % length];
        vec2_add(&first, pos);
        vec2_add(&second, pos);
        draw_line(&first, &second);
    }
}

void draw_polygon_outline(const vec2_t *const points, const size_t length) {
    draw_polygon_outline_at(points, length, &(vec2_t) {0});
}
