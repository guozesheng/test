#include <stdio.h>
#include "fbtools.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/user.h>

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
    fb_close(&fbdev);
    
    return 0;
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
    pFbdev->fb_mem_offset = (unsigned long int)mmap(NULL, pFbdev->fb_fix.smem_len + pFbdev->fb_mem_offset, PROT_READ | PROT_WRITE, MAP_SHARED, pFbdev->fb, 0);

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
