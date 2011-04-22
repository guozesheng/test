/*
 * the array's assignment and print
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 5
typedef int type_t;

int show(type_t a[], int len);
int init_arr(type_t a[], int len);

int main(int argc, const char *argv[])
{
    type_t a[N] = {0};
    show(a, N);
    init_arr(a, N);
    show(a, N);

    return 0;
}

int show(type_t a[], int len)
{
    int i;
    for (i = 0; i < len; i++) 
    {
        printf("%4d", a[i]);
    }
    printf("\n");
    return 0;
}

int init_arr(type_t a[], int len)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < len; i++) 
    {
        a[i] = rand() % 100;
    }
    return 0;
}
