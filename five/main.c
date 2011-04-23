#include <stdio.h>
#include "main.h"

int main(int argc, const char *argv[])
{
    init_screen();
    //fb_one_pixel(300, 300, 0x0000ff00);
    //fb_line(300, 300, 100, 100, 0x0000ff00);
    //fb_line(0, 600, 1000, 400, 0x0000ff00);
    //fb_line(300, 300, 400, 1000, 0x0000ff00);
    fb_line(300, 300, 200, 1000, 0x0000ff00);

    return 0;
}
