#ifndef _MAIN_H_
#define _MAIN_H_

typedef unsigned int u32_t;

struct fbsrc_t
{
    int w;
    int h;
    int bpp;

    void *memo;
};

int init_screen(void);
int fb_one_pixel(int x, int y, u32_t color);

#endif
