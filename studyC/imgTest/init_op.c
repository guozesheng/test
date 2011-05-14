#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/fb.h>
#include <sys/mman.h>

struct fbsrc_t fb_v;

int init_screen(void)
{
    int fd;
    u32_t *p;
    struct fb_var_screeninfo fb_var;

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

    p = mmap(NULL, fb_v.w*fb_v.h*fb_v.bpp/8, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) 
    {
        perror("map");
        exit(1);
    }

    printf("x:%d, y:%d, b:%d\n", fb_v.w, fb_v.h, fb_v.bpp);

    fb_v.memo = p;

    //p[300 * 300] = 0x00ff00ff;
    
    close(fd);
    //munmap(p, fb_v.w*fb_v.h*fb_v.bpp/8);
    return 0;
}

int fb_one_pixel(int x, int y, u32_t color)
{
    *((u32_t *)fb_v.memo + x + y * fb_v.w) = color;
    
    return 0;
}
