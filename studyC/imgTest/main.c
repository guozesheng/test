#include "main.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
    init_screen();

    fb_one_pixel(300, 300, 0x00ff00ff);

    return 0;
}
