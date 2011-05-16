#include <stdio.h>
#include "fbtools.h"

void test(FBDEV fbdev)
{
    int i, j;

    fb_drawvline(&fbdev, 200, 100, 0x000000ff);
    fb_drawline(&fbdev, 300, 500, 100, 200, 0x00ff0000);
    fb_drawline(&fbdev, 400, 100, 500, 500, 0x00ff0000);
    fb_drawline(&fbdev, 350, 100, 500, 100, 0x0000ff00);
    fb_drawline(&fbdev, 350, 100, 350, 500, 0x0000ff00);

    // /*
    for (j = 0; j < 100; j++) 
    {
        if (j % 2) 
        {
            for (i = 0; i < 300; i += 2) 
            {
                fb_drawpixel(&fbdev, 512 + j, 384 + i, 0x00ff0000);
            }
        }
        else
        {
            for (i = 1; i < 300; i += 2) 
            {
                fb_drawpixel(&fbdev, 512 + j, 384 + i, 0x0000ff00);
            }
        }
    }
    for (i = 512 - 300/2; i < 512 + 300/2; i++) 
    {
        fb_drawpixel(&fbdev, i, 384+70, 0x00ff0000);
    }
   // */

   //fb_drawbg(&fbdev);
}
