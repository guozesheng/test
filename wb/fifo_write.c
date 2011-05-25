#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;
    int n;

    if ((fd = open("./hello.fifo", O_RDWR)) < 0) 
    {
        perror("open");
        exit(1);
    }

    n = write(fd, "Hello, world!\n", 14);
    if (n < 0) 
    {
        perror("write");
        exit(1);
    }
    
    close(fd);
    return 0;
}
