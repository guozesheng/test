/*
 * The class of "printf"
 */

#include <stdio.h>

int counter = 0;
char buf[64];

int main(int argc, const char *argv[])
{
    fprintf(stdout, "to stdout: %d \n", counter++);
    fprintf(stderr, "to stderr: %d \n", counter++);
    fprintf(stderr, "to stderr: %d \n", counter++);
    sprintf(buf, "test sprintf: %d \n", counter++);
    printf("%s\n", buf);

    return 0;
}
