#include <stdbool.h>
#include <graphx.h>
#include <keypadc.h>
#include "draw.h"
#include "physics.h"
#include "maps/testmap.h"

polygon_t test_poly = {
    .pos = VEC(100, 100),
    .vertex_offsets = (vec2_t[]) {VEC(0, 0), VEC(0, 50), VEC(50, 50)},
    .vertex_offsets_length = 3
};

void setup(void) {

}

void setup_gfx(void) {
    gfx_Begin();
    gfx_SetDrawBuffer();
}

bool tick(void) {
    kb_Scan();

    if (kb_Data[7] & kb_Left)
        test_poly.pos.x -= 1;
    if (kb_Data[7] & kb_Right)
        test_poly.pos.x += 1;
    if (kb_Data[7] & kb_Up)
        test_poly.pos.y += 1;
    if (kb_Data[7] & kb_Down)
        test_poly.pos.y -= 1;

    return !(kb_Data[6] & kb_Clear);
}

void render(void) {
    gfx_FillScreen(28);

    gfx_SetColor(0);
    dbg_draw_polygon_outline(map_testmap_points, map_testmap_points_length);
    gfx_SetColor(103);
    draw_polygon_outline_at(test_poly.vertex_offsets, test_poly.vertex_offsets_length, &test_poly.pos);
}

void cleanup_gfx(void) {
    gfx_End();
}

/* Main function, called first */
int main(void)
{
    setup();
    setup_gfx();

    while (tick()) {
        render();
        gfx_SwapDraw();
        gfx_Wait();
    }

    cleanup_gfx();

    /* Return 0 for success */
    return 0;
}
