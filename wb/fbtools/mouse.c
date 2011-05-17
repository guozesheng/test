#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fbtools.h"

static u32_t cursor_pixel[C_WIDTH * C_HEIGHT] = {
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
static u32_t save_cursor[C_WIDTH * C_HEIGHT] = {0};

int mouse_parse(int fd, mevent_t *mevent)
{
    s8_t buf[READ_MOUSE];
    int n;

    if ((n = read(fd, buf, READ_MOUSE)) > 0) 
    {

    // 1: left key; 2: right key; 4: middle key; 0: button kdy
        mevent->button = buf[0] & 0x07;
        mevent->dx = buf[1];
        mevent->dy = -buf[2];
        mevent->dz = buf[3];
    }
    else 
    {
        return -1;
    }

    
    return 0;
}

int mouse_save(PFBDEV pFbdev, int x, int y)
{
    int i, j;

    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            save_cursor[i + j * C_WIDTH] = *(u32_t *)(pFbdev->fb_mem + (x+i) + (y+j) * pFbdev->fb_var.xres);
        }
    }
    
    return 0;
}

int mouse_restore(PFBDEV pFbdev, int x, int y)
{
    int i, j;

    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            fb_drawpixel(pFbdev, x + i, y + j, save_cursor[i + j * C_WIDTH]);
        }
    }
    
    return 0;
}

int mouse_draw(PFBDEV pFbdev, int x, int y)
{
    int i, j;

    mouse_save(pFbdev, x, y);

    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            if (cursor_pixel[i + j * C_WIDTH] != T___) 
            {
                fb_drawpixel(pFbdev, x+i, y+j, cursor_pixel[i + j * C_WIDTH]);
            }
        }
    }
    
    return 0;
}

int mouse_test(PFBDEV pFbdev)
{
    int fd;
    
    if ((fd = open("/dev/input/mice", O_RDWR | O_NONBLOCK)) < 0) 
    {
        perror("mouse open");
        exit(1);
    }

    mevent_t mevent;
    int m_x = pFbdev->fb_var.xres / 2;
    int m_y = pFbdev->fb_var.yres / 2;

    mouse_draw(pFbdev, m_x, m_y);

    while (1) 
    {
        if (mouse_parse(fd, &mevent) == 0) 
        {
            mouse_restore(pFbdev, m_x, m_y);

            m_x += mevent.dx;
            m_y += mevent.dy;
            mouse_draw(pFbdev, m_x, m_y);
        }
    }

    return 0;
}
