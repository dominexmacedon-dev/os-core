#ifndef I_DISPLAY_H
#define I_DISPLAY_H

#include "../shared/types.h"
#include "../shared/status.h"

typedef struct
{
    u32 width;
    u32 height;
    u32 bpp;
} display_info_t;

status_t i_display_initialize(void);

status_t i_display_shutdown(void);

status_t i_display_clear_screen(void);

status_t i_display_draw_pixel(
    u32 x,
    u32 y,
    u32 color
);

status_t i_display_draw_line(
    u32 x1,
    u32 y1,
    u32 x2,
    u32 y2,
    u32 color
);

status_t i_display_draw_rect(
    u32 x,
    u32 y,
    u32 width,
    u32 height,
    u32 color
);

status_t i_display_fill_rect(
    u32 x,
    u32 y,
    u32 width,
    u32 height,
    u32 color
);

status_t i_display_draw_text(
    u32 x,
    u32 y,
    const char* text
);

display_info_t i_display_get_info(void);

#endif