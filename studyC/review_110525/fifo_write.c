#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;
    char str[] = "Hello, world!";

    fd = open("hello.fifo", O_RDWR);
    if (fd < 0) 
    {
        perror("open");
        exit(1);
    }

    if (write(fd, str, sizeof(str)) < 0)
    {
        perror("write");
        exit(1);
    }
    
    close(fd);
    return 0;
}
