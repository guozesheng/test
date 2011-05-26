#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[80];
    char str[] = "Hello, world!\n";

    if (pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0)    // parent
    {
        close(fd[0]);
        write(fd[1], str, sizeof(str));
        wait(NULL);
    }
    else            // child
    {
        close(fd[1]);
        n = read(fd[0], line, 4096);
        write(STDOUT_FILENO, line, n);
    }

    return 0;
}
