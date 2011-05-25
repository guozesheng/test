#include <stdio.h>
#include <string.h>
#include "main.h"

int main(int argc, const char *argv[])
{
    FBDEV fbdev;

    strcpy(fbdev.dev, "/dev/fb0");

    if (fb_init(&fbdev) == -1)
    {
        return -1;
    }

    draw_pixel(fbdev, 500, 500, 0x0000ff00);
    
    fb_destroy(fbdev);
    return 0;
}
