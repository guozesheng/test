#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "main.h"

extern const unsigned char fontdata_8x16[FONTDATAMAX];

int font_disp(char c, int x, int y, u32_t color)
{/*{{{*/
    int i, j;
    int font_w = 16;
    int font_h = 8;
    unsigned char mask = 0x01;
    int ic = toascii(c);
    int relx = x;

    for (i = ic * font_w; i < ic * font_w + font_w; i++, y++) 
    {
        for (j = font_h, x = relx; j > 0; j--, x++) 
        {
            if ((fontdata_8x16[i] & (mask << j)) > 0)
            {
                fb_one_pixel(x, y, color);
            }
        }
    }

    return 0;/*}}}*/
}

int font_test(char *str, int x, int y, u32_t color)
{
    int font_w = 10;

    while (*str != '\0') 
    {
        font_disp(*str, x, y, color);
        str++;
        x += font_w;
        usleep(100000);
    }
    
    return 0;
}
