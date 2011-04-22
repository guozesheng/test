/*
 * decimal to hexadecimal by array
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100

int foo(int n);

int main(int argc, const char *argv[])
{
    int n = atoi(argv[1]);
    foo(n);

    return 0;
}

int foo(int n)
{
    char a[N];
    int i, temp;
    for (i = 0; n != 0; i++) 
    {
        temp = n % 16;
        if (temp <= 9) 
        {
            a[i] = temp + '0';
        }
        else 
        {
            a[i] = (temp - 10) + 'A';
        }
        n /= 16;
    }
    while (i) 
    {
        printf("%c", a[--i]);
    }
    printf("\n");

    return 0;
}
