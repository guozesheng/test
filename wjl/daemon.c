#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int fd, i;
    pid_t pid;
    char str[] = "Hello, world!"; 

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid > 0) 
    {
        exit(0);
    }

    setsid();
    chdir("/");
    umask(0);

    for (i = 0; i < getdtablesize(); i++) 
    {
        close(i);
    }

    while (1) 
    {
        if ((fd = open("/tmp/logfile", O_CREAT | O_WRONLY | O_APPEND)) < 0)
        {
            perror("open file error");
            return 4;
        }
        write(fd, str, strlen(str) + 1);
        close(fd);
        sleep(10);
    }
    
    return 0;
}
