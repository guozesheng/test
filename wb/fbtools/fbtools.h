#ifndef _FBTOOLS_H_
#define _FBTOOLS_H_

#include <linux/fb.h>

#define C_WIDTH     10
#define C_HEIGHT    17
#define T___        0xFFFFFFFF
#define BORD        0x0
#define X___        0xffff
#define READ_MOUSE  8

typedef unsigned short int u16_t;
typedef unsigned int u32_t;
typedef char s8_t;

typedef struct fbdev
{
    int fb;
    unsigned long fb_mem_offset;
    unsigned long fb_mem;
    struct fb_fix_screeninfo fb_fix;
    struct fb_var_screeninfo fb_var;
    char dev[20];
} FBDEV, *PFBDEV;

typedef struct 
{
    int dx;
    int dy;
    int dz;
    int button;
} mevent_t;

int fb_open(PFBDEV pFbdev);
int fb_close(PFBDEV pFbdev);
void fb_memset(void *addr, int c, size_t len);
void fb_drawline(PFBDEV pFbdev, int x1, int y1, int x2, int y2, u32_t color);
void fb_drawbg(PFBDEV pFbdev);
void fb_drawvline(PFBDEV pFbdev, int x, int y, u32_t color);
void fb_drawpixel(PFBDEV pFbdev, int x, int y, u32_t color);
void fb_drawcircle(PFBDEV pFbdev, int x, int y, int r, u32_t color);
int mouse_draw(PFBDEV pFbdev, int x, int y);
int mouse_test(PFBDEV pFbdev);
void test(FBDEV fbdev);

#endif
