#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/user.h>
#include <time.h>
#include <math.h>
#include "fbtools.h"

int main(int argc, const char *argv[])
{
    FBDEV fbdev;
    memset(&fbdev, 0, sizeof(FBDEV));
    strcpy(fbdev.dev, "/dev/fb0");

    if (fb_open(&fbdev) == -1) 
    {
        printf("open frame buffer error\n");
        exit(1);
    }

    fb_memset((void *)(fbdev.fb_mem + fbdev.fb_mem_offset), 0, fbdev.fb_fix.smem_len);

    //test(fbdev);

    fb_close(&fbdev);
    return 0;
}

void fb_drawcircle(PFBDEV pFbdev, int x, int y, int r, u32_t color)
{
    int i;

    for (i = 0; i < r; i++) 
    {
        fb_drawpixel(pFbdev, x + i, y + sqrt(r * r - i * i), color);
    }
}

void fb_drawline(PFBDEV pFbdev, int x1, int y1, int x2, int y2, u32_t color)
{
    int i;
    int x, xe, y, ye;
    float a;
    float b;

    if (x1 == x2) 
    {
        y = (y1 < y2 ) ? y1 : y2;
        ye = (y1 < y2 ) ? y2 : y1;
        for (i = y; i < ye; i++) 
        {
            fb_drawpixel(pFbdev, x1, i, color);
        }
        return;
    }

    a = (y2 - y1) / (float)(x2 - x1);
    b = y1 - a * x1;

    if (a <= 0) 
    {
        x = (x1 < x2) ? x1 : x2;
        xe = (x1 < x2) ? x2 : x1;
        for (i = x; i < xe; i++) 
        {
            if (((int)((a * i + b) * 10) % 10) > 4)
            {
                y = a * i + b + 1;
            }
            else 
            {
                y= a * i + b;
            }
            fb_drawpixel(pFbdev, i, y, color);
        }
    }
    else
    {
        y = (y1 < y2 ) ? y1 : y2;
        ye = (y1 < y2 ) ? y2 : y1;
        for (i = y; i < ye; i++) 
        {
            if (((int)(((i - b) / a) * 10) % 10) > 4) 
            {
                x = (i - b) / a + 1;
            }
            else 
            {
                x = (i - b) / a;
            }
            fb_drawpixel(pFbdev, x, i, color);
        }
    }
}

//*
void fb_drawbg(PFBDEV pFbdev)
{
    int i;

    srand(time(NULL));
    while (1)
    {
        usleep(90000);
        fb_memset((void *)(pFbdev->fb_mem + pFbdev->fb_mem_offset), 0, pFbdev->fb_fix.smem_len);
        for (i = 0; i < 1000; i++) 
        {
            fb_drawpixel(pFbdev, rand()%1024, rand()%768, rand()%0x00ffffff);
        }
    }
}
// */

void fb_drawvline(PFBDEV pFbdev, int x, int y, u32_t color)
{
    int i;
    for (i = 0; i < pFbdev->fb_var.yres; i++) 
    {
        fb_drawpixel(pFbdev, x, i, color);
    }
}

void fb_drawpixel(PFBDEV pFbdev, int x, int y, u32_t color)
{
    int i;
    u32_t *p = (u32_t *)pFbdev->fb_mem;

    i = x + y * pFbdev->fb_var.xres;
    p[i] = color;
}

void fb_memset(void *addr, int c, size_t len)
{
    memset(addr, c, len);
}

int fb_open(PFBDEV pFbdev)
{
    pFbdev->fb = open(pFbdev->dev, O_RDWR);
    
    if (pFbdev->fb < 0) 
    {
        perror("open");
        return -1;
    }
    if (ioctl(pFbdev->fb, FBIOGET_VSCREENINFO, &(pFbdev->fb_var)) == -1)
    {
        perror("FBIOGET_VSCREENINFO");
        return -1;
    }
    if (ioctl(pFbdev->fb, FBIOGET_FSCREENINFO, &(pFbdev->fb_fix)) == -1)
    {
        perror("FBIOGET_FSCREENINFO");
        return -1;
    }

    pFbdev->fb_mem_offset = (unsigned long)(pFbdev->fb_fix.smem_start) & (~PAGE_MASK); //?
    pFbdev->fb_mem = (unsigned long int)mmap(NULL, pFbdev->fb_fix.smem_len + pFbdev->fb_mem_offset, PROT_READ | PROT_WRITE, MAP_SHARED, pFbdev->fb, 0);

    if ((long)pFbdev->fb_mem == -1) 
    {
        perror("mmap");
        return -1;
    }
    
    return 0;
}

int fb_close(PFBDEV pFbdev)
{
    close(pFbdev->fb);
    pFbdev->fb = -1;
    
    return 0;
}
