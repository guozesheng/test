#include <stdio.h>
#include "main.h"

int main(int argc, const char *argv[])
{
    init_screen();

    fb_one_pixel(300, 300, 0x00ff00ff);
    jpeg_main(argv[1]);

/*
    char str[] = "Hello, world! My name is Guo Zesheng.";
    font_test(str, 30, 100, 0x0000ff00);

    if (init_ft("shaonv.ttf", 0) != 0) 
    {
        fprintf(stderr, "Error init font\n");
        return 1;
    }
// */

//display_string("长春大学", 30, 170, 0x00ff0000);

    return 0;
}
