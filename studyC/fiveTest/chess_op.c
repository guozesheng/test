#include "main.h"

extern int mx;  // extern from mouse_op.c
extern int my;
char chess_board[(B_X-1) * (B_Y-1)] = {0};
char curent_player = 1;
u32_t curent_color = BLACK;

int chess_check(int x, int y)
{
    int i, j;
    int xmove[8] = {1, 1, 0, -1, -1,  -1, 0, 1};
    int ymove[8] = {0, -1, -1, -1, 0, 1, 1 ,1};
    char other_player = curent_player == 1 ? 2 : 1;
    int times = 0;

    while (chess_board[(x+xmove[0]) + (y+ymove[0]) * B_X] == other_player) 
    {
        times++;
    }
    
    return 0;
}

int chess_do(void)
{
    int x, y;
    int lx, ly;

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

    if (chess_board[lx + ly*B_X] == 0) 
    {
        fb_circle_fill(x, y, C_R, curent_color);

        if (curent_player == 1) 
        {
            chess_board[lx + ly*B_X] = curent_player;
            curent_player = 2;
            curent_color = WHITE;
        }
        else 
        {
            chess_board[lx + ly*B_X] = curent_player;
            curent_player = 1;
            curent_color = BLACK;
        }
    }

    return 0;
}
