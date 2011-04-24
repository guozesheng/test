#include <stdio.h>
#include "main.h"

extern int mx;
extern int my;
char flag = 0;

int chess_do(u32_t color)
{
    int x = mx;
    int y = my;

    if (flag == 0) 
    {
        print_board(GRAY, YELLOW);
        flag = 0xff;
        return 0;
    }

    if (x < ST_X || (x > ST_X + SPACE * (B_X -1))) 
    {
        return 0;
    }
    if (y < ST_Y || (y > ST_Y + SPACE * (B_Y -1))) 
    {
        return 0;
    }

    x = (x - ST_X) % SPACE;
    y = (y - ST_Y) % SPACE;

    if (x < (SPACE / 2)) 
    {
        x = mx - x;
    }
    else 
    {
        x = mx + (SPACE - x);
    }
    if (y < (SPACE / 2)) 
    {
        y = my - y;
    }
    else 
    {
        y = my + (SPACE - y);
    }

    fb_circle(x, y, 13, color);

    return 0;
}
