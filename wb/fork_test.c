#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    pid_t pid;
    char *message;
    int n;

    pid = fork();

    if (pid < 0) 
    {
        perror("fork failed");
        exit(1);
    }
    if (pid == 0) 
    {
        message = "This is the child";
        n = 6;
    }
    else 
    {
        message = "This is the parent";
        n = 3;
    }
    for (; n > 0; n--) 
    {
        printf("%s\n", message);
        sleep(1);
    }

    return 0;
}
