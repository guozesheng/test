/*
 * The pointer and the array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   5

int  init_arr(int a[], int len);
int show(int a[], int len);
int foo(int a[], int len,int *f, int *s);

int main(int argc, const char *argv[])
{
    int a[N] = {1, 2, 3, 4, 5};
    int len = N;
    int f, s;

    init_arr(a, len);
    show(a, len);

    foo(a, len, &f, &s);
    printf("first = %d\n", f);
    printf("second = %d\n", s);

    printf("\n");
    return 0;
}

int  init_arr(int a[], int len)
{
    srand(time(NULL));
    int i;
    
    for (i = 0; i < len; i++) 
    {
        a[i] = rand() % 100;
    }
    
    return 0;
}

int show(int a[], int len)
{
    int i;

    for (i = 0; i < len; i++) 
    {
        printf("%5d", a[i]);
    }
    
    printf("\n");
    return 0;
}

#if 0

int foo(int a[], int len, int *f, int *s)
{
    int i;
    int max = 0;

    for (i = 0; i < len; i++) 
    {
        if (a[max] < a[i]) 
        {
            max = i;
        }
    }

    int sec = (max == 0) ? 1 : 0;
    
    for (i = 0; i < count; ++i) 
    {
        if ((a[sec] < a[i]) && (i != max)) 
        {
            sec = i;
        }
    }

    *f = a[max];
    *s = a[sec];
    
    return 0;
}

#else

int foo(int a[], int len, int *f, int *s)
{
    int i;
    int max = (a[0] > a[1]) ? 0 : 1;
    int sec = (a[0] < a[1]) ? 0 : 1;

    for (i = 2; i < len; i++) 
    {
        if (a[max] < a[i]) 
        {
            sec = max;
            max = i;
        }
        else if (a[sec] < a[i])
        {
            sec = i;
        }
    }

    *f = a[max];
    *s = a[sec];
    
    return 0;
}

#endif
