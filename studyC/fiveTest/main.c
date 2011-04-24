#include <stdio.h>
#include "main.h"

int main(int argc, const char *argv[])
{
    init_screen();
    
    fb_pixel(300, 300, 0x0000ff00);

    return 0;
}
