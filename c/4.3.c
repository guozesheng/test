/*
 * sum = 1 + 3 + 5 + ... + 99
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i;
    int sum = 0;

    for (i = 0; i <= 99; i += 2) 
    {
        sum += i;
    }

    printf("1 + 3 + 5 + ... + 99 = %d\n", sum);

    return 0;
}
