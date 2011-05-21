#include "main.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
    init_screen();

    fb_one_pixel(300, 300, 0x00ff00ff);
    jpeg_main(argv[1]);

    char str[] = "Hello, world! My name is Guo Zesheng.";
    font_test(str, 30, 100, 0x0000ff00);

    return 0;
}
