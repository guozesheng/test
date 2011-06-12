/*
 * Convert the command line parameter to integer and add them.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc < 3) 
    {
        printf("Please input: %s <a> <b> \n", argv[0]);
        return 1;
    }

    printf("%s + %s = %d\n", argv[1], argv[2], atoi(argv[1]) + atoi(argv[2]));

    return 0;
}
