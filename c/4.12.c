/*
 * 求1-100的素数
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i;

    for (i = 1; i < 100; i++) 
    {
        if (!isPrime(i)) 
        {
            continue;
        }
        printf("%5d", i);
    }

    printf("\n");
    return 0;
}

int isPrime(int num)
{
    int i;
    for (i = 2; i < num; i++) 
    {
        if (num % i == 0) 
        {
            return 0;
        }
    }
    if (i == num) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
