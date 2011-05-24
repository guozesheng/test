#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 80

int main(int argc, const char *argv[])
{
    int n;
    int fd[2], fd2[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0) 
    {
        perror("pipe");
        exit(1);
    }
    if ((pid = fork()) < 0) 
    {
        perror("fork");
        exit(1);
    }
    if (pid > 0)    // parent
    {
        close(fd[0]);
        write(fd[1], "Hello, world\n", 13);

        close(fd2[1]);
        n = read(fd2[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
        wait(NULL);
    }
    else            // child
    {
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);

        close(fd2[0]);
        write(fd2[1], "Received!\n", 10);
    }
    
    return 0;
}
