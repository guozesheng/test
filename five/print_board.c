#include <stdio.h>
#include "main.h"

int print_board(u32_t color)
{
    int i = 0;
    
    for (i = 0; i < B_Y; i++) 
    {
        fb_line(ST_X, ST_Y+i*SPACE, ST_X+(B_X-1)*SPACE, ST_Y+i*SPACE, color);
    }
    
    return 0;
}
