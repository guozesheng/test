#include "main.h"

extern int mx;  // extern from mouse_op.c
extern int my;
char curent_player = 1;
u32_t curent_color = BLACK;

int chess_do(void)
{
    int x, y;

    if (mx < ST_X || mx > ST_X + SPACE*(B_X-1)) 
    {
        return 0;
    }
    if (my <ST_Y || my > ST_Y + SPACE*(B_Y-1)) 
    {
        return 0;
    }

    x = ST_X + ((mx - ST_X) / SPACE) * SPACE + SPACE / 2;   // draw circle at center
    y = ST_Y + ((my - ST_Y) / SPACE) * SPACE + SPACE / 2;

    if (curent_player == 1) 
    {
        fb_circle_fill(x, y, C_R, curent_color);
        curent_player = 2;
        curent_color = WHITE;
    }
    else 
    {
        fb_circle_fill(x, y, C_R, curent_color);
        curent_player = 1;
        curent_color = BLACK;
    }

    return 0;
}
