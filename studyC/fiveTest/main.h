#ifndef _MAIN_H_
#define _MAIN_H_

#define YELLOW  0x00eebb00
#define BLACK   0x00
#define WHITE   0x00ffffff
#define RED     0x00ff0000
#define GRAY    0x00222222

#define T___    YELLOW
#define BORD    0x0f
#define X___    0x00fffff
#define C_W     10
#define C_H     17

#define ST_X    360
#define ST_Y    100
#define B_X     9
#define B_Y     9
#define SPACE   70

typedef unsigned int u32_t;

typedef struct
{
    int w;
    int h;
    int bpp;

    void *memo;
} fbsrc_t;

typedef struct
{
    int dx;
    int dy;
    int dz;

    char button;
} mouse_event;

int init_screen(void);
int fb_pixel(int x, int y, u32_t color);
int fb_line(int x1, int y1, int x2, int y2, u32_t color);
int fb_circle_fill(int x0, int y0, int r, u32_t color);
int draw_cursor(int x, int y);
int mouse_doing(void);
int save_bg(int x, int y);
int rest_bg(int x, int y);
int board_print(u32_t color_line, u32_t color_bg);

#endif
