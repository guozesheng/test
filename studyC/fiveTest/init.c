#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/fb.h>
#include "main.h"

int init_screen(void)
{
    int fd;
    struct fb_var_screeninfo fb_var;    //#include <linux/fb.h>
    
    fd = open("/dev/fb0", O_RDWR);
    if (fd == -1) 
    {
        perror("fb0");
        exit(0);
    }
    
    close(fd);
    return 0;
}
