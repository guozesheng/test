/*
 * the size of the pointer
 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char *x = "012345";

    printf("sizeof(x) = %d, strlen(x) = %d\n", sizeof(x), strlen(x));
    printf("sizeof(char *) = %d, sizeof(int *) = %d\n", sizeof(char *), sizeof(int *));

    return 0;
}
