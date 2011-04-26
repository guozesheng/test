#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

int get_m_info(int fd, mouse_event *p)
{
    int n;
    char buf[8];

    n = read(fd, buf, 3);

    if (n > 0) 
    {
        p -> dx = buf[1];
        p -> dy = -buf[2];
        p -> button = (buf[0]&0x07);
    }
    
    return n;
}

int mouse_doing(void)
{
    int fd;
    mouse_event m_event;

    fd = open("/dev/input/mice", O_RDWR|O_NONBLOCK);
    if (fd == -1) 
    {
        perror("mice");
        exit(0);
    }

    mx = fb_v.w / 2;    //initial the coordinates
    my = fb_v.h / 2;

    draw_cursor(mx, my);

    while (1) 
    {
        if (get_m_info(fd, &m_event) > 0) 
        {
            mx += m_event.dx;
            my += m_event.dy;
            mx = (mx < 0) ? 0 : mx;
            my = (my < 0) ? 0 : my;

            draw_cursor(mx, my);
        }
    }
    
    return 0;
}
