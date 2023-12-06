#include <stdbool.h>
#include <graphx.h>
#include <keypadc.h>
#include "draw.h"
#include "maps/testmap.h"

void setup(void) {

}

void setup_gfx(void) {
    gfx_Begin();
    gfx_SetDrawBuffer();
}

bool tick(void) {
    kb_Scan();

    return !(kb_Data[6] & kb_Clear);
}

void render(void) {
    dbg_draw_polygon(map_testmap_points, map_testmap_points_length);
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
