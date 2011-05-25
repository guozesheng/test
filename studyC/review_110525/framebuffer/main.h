#ifndef _MAIN_H_
#define _MAIN_H_

#include <linux/fb.h>

typedef unsigned int u32_t;

typedef struct fbdev
{
    int fb;
    void *memo;
    struct fb_var_screeninfo fb_var;
    char dev[20];
} FBDEV, *PFBDEV;

int fb_init(PFBDEV pFbdev);
int fb_destroy(FBDEV fbdev);
int fb_memset(void *addr, int c, size_t len);
int draw_pixel(FBDEV fbdev, int x, int y, u32_t color);

#endif
