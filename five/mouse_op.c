#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

extern fbsrc_t fb_v;
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

static u32_t bg_save[C_H * C_W] = {0};

int draw_cursor(int x, int y)
{
    int i = 0;
    int j = 0;

    save_bg(x, y);

    for (j = 0; j < C_H; j++) 
    {
        for (i = 0; i < C_W; i++) 
        {
            if (cursor_pixel[i+j*C_W] != T___) 
            {
                fb_one_pixel(x+i, y+j, cursor_pixel[i+j*C_W]);
            }
        }
    }

    return 0;
}

int save_bg(int x, int y)
{
    int i = 0;
    int j = 0;

    for (j = 0; j < C_H; j++) 
    {
        for (i = 0; i < C_W; i++) 
        {
            bg_save[i+j*C_W] = *((u32_t *)fb_v.memo+x+i+(y+j)*fb_v.w);
        }
    }

    return 0;
}

int restore(int x, int y)
{
    int i = 0;
    int j = 0;

    for (j = 0; j < C_H; j++) 
    {
        for (i = 0; i < C_W; i++) 
        {
            fb_one_pixel(x+i, y+j, bg_save[i+j*C_W]);
        }
    }
    
    return 0;
}

int get_m_info(int fd, mouse_event *p)
{
    int n;
    char buf[8];

    n = read(fd, buf, 3);   //man
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
    int press_flag = 0;
    int end_flag = 0;
    mouse_event m_event;
    fd = open("/dev/input/mice", O_RDWR|O_NONBLOCK); //?
    if (fd == -1) 
    {
        perror("mice");
        exit(0);
    }

    mx = fb_v.w / 2;    //initial the coordinates.
    my = fb_v.h / 2;

    draw_cursor(mx, my);

    while (1) 
    {
        if (get_m_info(fd, &m_event) > 0) 
        {
            restore(mx, my);
            mx += m_event.dx;
            my += m_event.dy;
            mx = (mx < 0) ? 0 : mx;
            my = (my < 0) ? 0 : my;

            if (mx > (fb_v.w - C_W)) 
            {
                mx = fb_v.w - C_W;
            }
            if (my > (fb_v.h - C_H)) 
            {
                my = fb_v.h - C_H;
            }

            switch (m_event.button)
            {
                case 0: 
                    if (press_flag == 1) 
                    {
                        press_flag = 0;
                        if (end_flag == 0) 
                        {
                            end_flag = chess_do();
                        }
                        else 
                        {
                            print_board(GRAY, YELLOW);
                            end_flag = 0;
                        }
                    }
                    else if (press_flag == 2) 
                    {
                        press_flag = 0;
                        chess_do();
                    }
                    break;
                case 1: press_flag = 1; break;
                case 2: press_flag = 2; break;
                case 3:  break;
                case 4:  break;
                default: break;
            }

            draw_cursor(mx, my);
        }
        usleep(1000);
    }
    
    return 0;
}
