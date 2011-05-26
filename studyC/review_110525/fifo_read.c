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

    fd = open("hello.fifo", O_RDWR);
    if (fd < 0) 
    {
        perror("open");
        exit(1);
    }

    if (read(fd, buf, 4096) < 0)
    {
        perror("read");
        exit(1);
    }

    printf("%s\n", buf);
    
    close(fd);
    return 0;
}
