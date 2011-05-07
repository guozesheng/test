#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd, fd_w;
    char temp[4096];
    int size;

    fd = open(argv[1], O_RDONLY);
    fd_w = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    while ((size = read(fd,temp, 1024)))
    {
        write(fd_w, temp, size);
    }

    close(fd);
    close(fd_w);
    return 0;
}
