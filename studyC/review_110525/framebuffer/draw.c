#include <stdio.h>
#include "main.h"

int draw_pixel(FBDEV fbdev, int x, int y, u32_t color)
{
    *((u32_t *)fbdev.memo + x + y * fbdev.fb_var.xres) = color;
    
    return 0;
}
