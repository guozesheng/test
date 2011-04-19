#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    printf("%ld\n", strtol(argv[1], NULL, atoi(argv[2])));

    return 0;
}
