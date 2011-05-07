#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd, fd_w;
    //char str[] = "Hello, world!";
    char temp[4096];
    int size;

    fd = open("a.text", O_RDONLY);
    fd_w = open("a.write", O_WRONLY | O_CREAT, 0666);

    size = read(fd,temp, 100);
    write(fd_w, temp, size);

    close(fd);
    close(fd_w);
    return 0;
}
