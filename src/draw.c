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

void draw_polygon(const vec2_t *const points, const size_t length) {
    for (size_t i = 0; i < length - 1; i++) {
        draw_line(points + i, points + i + 1);
    }

    draw_line(points + 0, points + length - 1);
}
