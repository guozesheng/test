/*
 * Print the command line parameter
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    printf("argc = %d\n", argc);

    int i = 0;

    while (argv[i] != NULL) 
    {
        printf("argv[%d] = %s\n", i, argv[i]);
        i++;
    }

    int n =atoi(argv[1]);
    printf("n = %d\n", n);
    
    return 0;
}
