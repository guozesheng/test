#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include "main.h"

fbsrc_t fb_v;

int init_screen(void)
{
    int fd;
    struct fb_var_screeninfo fb_var;    //#include <linux/fb.h>
    u32_t *p = NULL;
    
    fd = open("/dev/fb0", O_RDWR);
    if (fd == -1) 
    {
        perror("fb0");
        exit(0);
    }
    if (ioctl(fd, FBIOGET_VSCREENINFO, &fb_var) == -1)  //#inclucde <sys/ioctl.h>
    {
        perror("ioctl");
        exit(0);
    }

    fb_v.w = fb_var.xres;    //get the screen's width and heigth and bits
    fb_v.h = fb_var.yres;
    fb_v.bpp = fb_var.bits_per_pixel;

    //printf("x=%d\ty=%d\tbits=%d\n", fb_v.w, fb_v.h, fb_v.bpp);

    p = mmap(NULL, fb_v.w*fb_v.h*fb_v.bpp/8, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);  //#include <sys/mman.h>
    if (p == MAP_FAILED) 
    {
        perror("map");
        exit(0);
    }

    fb_v.memo = p;

    //int x = 1279;     //for TEST
    //int y = 0;
    //p[x+y*fb_v.w] = 0x000000ff;
    
    close(fd);
    return 0;
}

int fb_pixel(int x, int y, u32_t color)
{
    *((u32_t *)fb_v.memo + x + y * fb_v.w) = color;
    
    return 0;
}
