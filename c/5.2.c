/*
 *  n!
 */

#include <stdio.h>

int factoria(int n);

int main(int argc, const char *argv[])
{
    int n;
    printf("Please input a num < 15:");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factoria(n));

    return 0;
}

int factoria(int n)
{
    if (n == 0) 
    {
        return 1;
    }
    else 
    {
        return n * factoria(n - 1);
    }
}
