#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd;

    fd = open("a.text", O_RDWR);
    if (fd) 
    {
        lseek(fd, 3, SEEK_SET);
        write(fd, "G", 1);
    }
    
    close(fd);
    return 0;
}
