#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;
    char buf[4096];
    int n;

    if ((fd = open("./hello.fifo", O_RDWR)) < 0) 
    {
        perror("open");
        exit(1);
    }

    n = read(fd, buf, 4096);
    if (n < 0) 
    {
        perror("read");
        exit(1);
    }
    printf("read data is: %s\n", buf);
    
    close(fd);
    return 0;
}
