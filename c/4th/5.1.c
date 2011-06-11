/*
 * Ponter arrays And array ponter
 */

#include <stdio.h>

int foo(int a[], int len);
int pri(int (*p)[10]);

int main(int argc, const char *argv[])
{
    //int (*p)[10] = (int (*)[10])100;
    int (*p)[10];
    int a[10];
    int *q[10];
    p = &a;
    q[0] = (int *)100;

    foo(a, 10);

    //printf("%d\n", p[0][1]);
    //printf("%d\n", *(*p + 2));
    pri(p);
    
    return 0;
}

int foo(int a[], int len)
{
    int i;

    for (i = 0; i < len; i++) 
    {
        a[i] = i + 1;
    }
    
    return 0;
}

int pri(int (*p)[10])
{
    int i;

    for (i = 0; i < 10; i++) 
    {
        printf("%3d", *(*p + i));
    }
    
    printf("\n");
    return 0;
}
