#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/fb.h>

int main(int argc, const char *argv[])
{
    struct fb_var_screeninfo fb_var;

    int fd = open("/dev/fb0", O_RDWR);
    ioctl(fd, FBIOGET_VSCREENINFO, &fb_var);

    printf("width:%d\thigh:%d\tbpp:%d\n", fb_var.xres, fb_var.yres, fb_var.bits_per_pixel);
    
    return 0;
}
