#include "main.h"

extern int mx;  // extern from mouse_op.c
extern int my;

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

    x = ST_X + ((mx - ST_X) / SPACE) * SPACE + SPACE / 2;
    y = ST_Y + ((my - ST_Y) / SPACE) * SPACE + SPACE / 2;

    fb_circle_fill(x, y, C_R, WHITE);

    return 0;
}
