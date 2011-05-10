/*
 * The application of pointer type functions
 */

#include <stdio.h>

int *foo(int *q);

int main(int argc, const char *argv[])
{
    int *p = NULL;

    p = foo(p);
    printf("%d\n", *p);

    return 0;
}

int *foo(int *q)
{
    static int a = 5;
    int *p = &a;

    printf("%d\n", *p);
    
    return p;
}
