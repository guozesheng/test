/*
 *  Di Gui Qiu He
 */

#include <stdio.h>

int sum(int n);

int main(int argc, const char *argv[])
{
    int n;
    printf("Please input a number < 15:");
    scanf("%d", &n);
    printf("1 + 2 + 3 + .. + %d = %d\n", n, sum(n));

    return 0;
}

int sum(int n)
{
    if (n == 0) 
    {
        return 0;
    }
    else 
    {
        return n + sum(n - 1);
    }
}
