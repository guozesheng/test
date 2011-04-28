#include <stdio.h>
#include "main.h"

extern int mx;  // 2 extern from mouse_op.c
extern int my;
extern char chess_board[(B_X-1) * (B_Y-1)]; // 4 extern from init.c
extern char curent_player;
extern char other_player;
extern u32_t curent_color;

int chess_check(int x, int y)
{
    int i, j;
    int xmove[8] = {1, 1, 0, -1, -1,  -1, 0, 1};
    int ymove[8] = {0, -1, -1, -1, 0, 1, 1 ,1};
    int xt, yt;
    int times = 0;

    for (j = 0; j < 8; j++) 
    {
        xt = x + xmove[j];
        yt = y + ymove[j];
        while (chess_board[xt + yt * (B_X-1)] == other_player && xt >= 0 && xt < B_X-1 && yt >= 0 && yt < B_Y-1) 
        {
            times++;
            xt += xmove[j];
            yt += ymove[j];
        }
        if (chess_board[xt + yt * (B_X-1)] != curent_player) 
        {
            times = 0;
        }
        for (i = 0, xt = x + xmove[j], yt = y + ymove[j]; i < times; i++, xt += xmove[j], yt += ymove[j]) 
        {
            fb_circle_fill(xt*SPACE + ST_X + SPACE/2, yt*SPACE + ST_Y + SPACE/2, C_R, curent_color);
            chess_board[xt + yt * (B_X-1)] = curent_player;
        }
    }
    
    return 0;
}

int chess_do(void)
{
    int x, y;
    int lx, ly;

    other_player = curent_player == 1 ? 2 : 1;

    if (mx < ST_X || mx > ST_X + SPACE*(B_X-1)) 
    {
        return 0;
    }
    if (my <ST_Y || my > ST_Y + SPACE*(B_Y-1)) 
    {
        return 0;
    }

    x = ST_X + ((mx - ST_X) / SPACE) * SPACE + SPACE / 2;   // draw circle at center
    y = ST_Y + ((my - ST_Y) / SPACE) * SPACE + SPACE / 2;

    lx = (x - ST_X) / SPACE;
    ly = (y - ST_Y) / SPACE;

    if (chess_board[lx + ly*(B_X-1)] == 0) 
    {
        fb_circle_fill(x, y, C_R, curent_color);
        chess_board[lx + ly*(B_X-1)] = curent_player;
        chess_check(lx, ly);

        if (curent_player == 1) 
        {
            curent_color = WHITE;
        }
        else 
        {
            curent_color = BLACK;
        }
        curent_player = other_player;
    }

    return 0;
}
