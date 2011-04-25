#include <stdio.h>
#include "main.h"

int main(int argc, const char *argv[])
{
    init_screen();
    
    fb_pixel(200, 300, 0x0000ff00);
    fb_line(300, 300, 350, 400, 0x00ff0000);
    fb_circle_fill(400, 300, 100, 0x0000ff00);

    mouse_doing();

    return 0;
}
