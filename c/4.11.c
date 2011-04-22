/*
 * break 和 goto 的用法--hello.c
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i, j;

    printf("hello, Cruel World!\n");

    for (i = 0; i < 4; i++) 
    {
        for (j = 0; j < 10; j++) 
        {
            printf("(i, j) = (%d, %d)\n", i, j);
            if (2 == j) 
            {
                break;
            }
            else if (4 == j)
            {
                goto out;
            }
        }
    }

    out:
    return 0;
}
