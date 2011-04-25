#include <stdlib.h>
#include "main.h"

int fb_line(int x1, int y1, int x2, int y2, u32_t color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 0;
    int inc = (dx * dy < 0) ? -1 : 1;
    
    dy = abs(dy);
    p = 2*dy - dx;

    while (x1 <= x2) 
    {
        fb_pixel(x1, y1, color);
        if (p > 0) 
        {
            y1 += inc;
            p += 2 * (dy - dx);
        }
        else 
        {
            p += dy;
        }

        x1++;
    }
    
    return 0;
}
