#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;

    if ((fd = open("a.text", O_RDWR)) < 0)
    {
        perror("open fail");
        exit(1);
    }

    lseek(fd, 2, SEEK_SET);

    write(fd, "a", 1);

    close(fd);
    return 0;
}
