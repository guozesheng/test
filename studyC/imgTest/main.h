#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <jpeglib.h>
#include <jerror.h>

typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;

#define FONTDATAMAX 4096

struct fbsrc_t
{
    int w;
    int h;
    int bpp;

    void *memo;
};

int init_screen(void);
int fb_one_pixel(int x, int y, u32_t color);
int jpeg_main(const char *img_file);
int disp_lefttoright(u32_t *buf, JDIMENSION jpeg_width, JDIMENSION jpeg_height, int sleeptime);
int disp_uptodown(u32_t *buf, JDIMENSION jpeg_width, JDIMENSION jpeg_height, int sleeptime);
int disp_scroll(u32_t *buf, JDIMENSION jpeg_width, JDIMENSION jpeg_height, int sleeptime);
int font_test(char *str, int x, int y, u32_t color);

#endif
