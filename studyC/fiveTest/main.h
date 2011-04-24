#ifndef _MAIN_H_
#define _MAIN_H_

typedef unsigned int u32_t;

typedef struct
{
    int w;
    int h;
    int bpp;

    void *memo;
} fbsrc_t;

int init_screen(void);
int fb_pixel(int x, int y, u32_t color);

#endif
