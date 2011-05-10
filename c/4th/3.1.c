/*
 * The pointer as the argument of the function
 */

#include <stdio.h>

int swp(int a, int b);
int swap(int *p, int *q);

int main(int argc, const char *argv[])
{
    int a = 5;
    int b = 6;

    swp(a, b);
    printf("swp:a = %d, b = %d\n", a, b);

    swap(&a, &b);
    printf("swap:a = %d, b = %d\n", a, b);

    return 0;
}

int swp(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    
    return 0;
}

int swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
    
    return 0;
}
