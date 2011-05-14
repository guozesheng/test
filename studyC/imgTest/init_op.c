#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/fb.h>

int init_screen(voi)
{
    int fd;
    struct fb_var_screeninfo fb_var;
    struct fbsrc_t fb_v;

    if ((fd = open("/dev/fb0", O_RDWR)) < 0) 
    {
        perror("fb0");
        exit(1);
    }
    if (ioctl(fd, FBIOGET_VSCREENINFO, &fb_var) < 0 )
    {
        perror("ioctl");
        exit(1);
    }

    fb_v.w = fb_var.xres;
    fb_v.h = fb_var.yres;
    fb_v.bpp = fb_var.bits_per_pixel;

    printf("x:%d, y:%d, b:%d\n", fb_v.w, fb_v.h, fb_v.bpp);
    
    close(fd);
    return 0;
}
