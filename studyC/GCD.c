/*
 * GCG: Greatest Common Divisor
 */

#include <stdio.h>

int my_gcd(int a, int b);

int main(int argc, const char *argv[])
{
    int a, b;

    printf("Please input the A and the B:");
    scanf("%d, %d", &a, &b);
    printf("%d\n", my_gcd(a, b));
    
    return 0;
}

int gcd(int a, int b)
{
    if (!(a % b)) 
    {
        return b;
    }
    else 
    {
        return gcd(a, a % b);
    }

    return -1;
}

int my_gcd(int a, int b)
{
    if (a > b) 
    {
        return gcd(a, b);
    }
    else 
    {
        return gcd(b, a);
    }
    
    return -1;
}
