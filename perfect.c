#include <stdio.h>

int perfect(int n);

int main(int argc, const char *argv[])
{
    int i, n = 1000;

    for (i = 1; i <= 1000; i++) 
    {
        if (perfect(i)) 
        {
            printf("%5d", i);
        }
    }

    printf("\n");
    return 0;
}

int perfect(int n)
{
    int sum = 0;
    int i;
    for (i = 1; i < n; i++) 
    {
        if (n % i == 0) 
        {
            sum += i;
        }
    }
    if (sum == n) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
