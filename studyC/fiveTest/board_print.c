#include "main.h"

int board_print(u32_t color_line, u32_t color_bg)
{
    int i, j;

    for (j = ST_Y - SPACE; j < ST_Y+B_X*SPACE; j++) 
    {
        for (i = ST_X - SPACE*2; i < ST_X + (B_Y+2)*SPACE; i++) 
        {
            fb_pixel(i, j, color_bg);
        }
    }

    for (i = 0; i < B_Y; i++) 
    {
        fb_line(ST_X, ST_Y+(i*SPACE), ST_X+(B_X-1)*SPACE, ST_Y+(i*SPACE), color_line);
    }

    for (i = 0; i < B_X; i++) 
    {
        fb_line(ST_X+(i*SPACE), ST_Y, ST_X+(i*SPACE), ST_Y+(B_Y-1)*SPACE, color_line);
    }
    
    return 0;
}
