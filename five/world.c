#include "main.h"

static u32_t num_1[16*16] = 
{
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,READ,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,READ,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,
    T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,
};

static u32_t num_2[16*16]=
{
    T___,T___,T___,T___,T___,READ,READ,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,READ,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,READ,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,READ,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,READ,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,T___,
};

static u32_t num_i[16*16] = 
{
    T___,T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,READ,READ,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,READ,READ,READ,READ,READ,READ,T___,T___,T___,T___,T___,
};

static u32_t num_w[16*16] = 
{
    READ,READ,READ,T___,T___,T___,READ,READ,READ,T___,T___,T___,READ,READ,READ,T___,
    READ,READ,READ,T___,T___,T___,READ,READ,READ,T___,T___,T___,READ,READ,READ,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    T___,T___,T___,T___,READ,T___,T___,T___,T___,T___,READ,T___,T___,T___,T___,T___,
};

int write_world(int x, int y, int num)
{
    int i = 0;
    int j = 0;
    int wr_w = 16;
    int wr_h = 16;
    u32_t *wr;
    
    if (num == 1) 
    {
        wr = num_1;
    }
    else if (num == 2) 
    {
        wr = num_2;
    }

    for (j = 0; j < wr_h; j++) 
    {
        for (i = 0; i < wr_w; i++) 
        {
            if (wr[i+j*wr_w] != T___) 
            {
                fb_one_pixel(x+i, y+j, wr[i+j*wr_w]);
            }
        }
    }

    return 0;
}
