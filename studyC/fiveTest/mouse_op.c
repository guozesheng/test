#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

extern fbsrc_t fb_v;    //extern form init.c
int mx, my;

static u32_t cursor_pixel[C_W * C_H] = 
{
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,  
    BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___,
    BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD,
    BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD,
    BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___,
    BORD,X___,BORD,T___,BORD,X___,X___,BORD,T___,T___,
    BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___,
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
    T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___
};

int draw_cursor(int x, int y)
{
    int i, j;

    for (j = 0; j < C_H; j++) 
    {
        for (i = 0; i < C_W; i++) 
        {
            if (cursor_pixel[i + j*C_W] != T___) 
            {
            
                fb_pixel(x+i, y+j, cursor_pixel[i + j*C_W]);
            }
        }
    }
    
    return 0;
}

int mouse_doing(void)
{
    int fd;

    fd = open("/dev/input/mice", O_RDWR|O_NONBLOCK);
    if (fd == -1) 
    {
        perror("mice");
        exit(0);
    }

    mx = fb_v.w / 2;    //initial the coordinates
    my = fb_v.h / 2;

    draw_cursor(mx, my);
    
    return 0;
}
