/*
 * Basic use of pointer
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 0;
    int *q = 0;
    int **p = 0;

    p = &q;
    q = &a;
    **p = 5;
    a = 5;
    *q = 5;

    return 0;
}

/*
 * In this, p is a pointer point to a pointer. So the **p is the value of the
 * pointed (a). The *p is the address of the pointed (&a or q). The p is the
 * address of the pointed pointer (&q).
