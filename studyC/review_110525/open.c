#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;
    int n;
    char str[4096] = "Hello, world!\n";

    fd = open("a.text", O_WRONLY | O_CREAT | O_EXCL, 0666);

    if (fd > 0) 
    {
        write(fd, str, sizeof(str));
    }
    else 
    {
        fd = open("a.text", O_RDONLY);
        while ((n = read(fd, str, 1)) > 0) 
        {
            write(STDOUT_FILENO, str, 1);
        }
    }
    
    close(fd);
    return 0;
}
