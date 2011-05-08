/*
 * Sort int by pointer
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int init_array(int *a, int len, int max);
int print_array(int *a, int len);
int sort_array(int *a, int len);

int main(int argc, const char *argv[])
{
    int a[10];

    init_array(a, 10, 30);
    printf("Befor sort:\n");
    print_array(a, 10);

    sort_array(a, 10);
    printf("After sort:\n");
    print_array(a, 10);

    return 0;
}

int sort_array(int *a, int len)
{
    int *p, *q, *pos;
    int tmp;

    for (p = a; p - a < len - 1; p++) 
    {
        for (q = p + 1; q - a < len; q++) 
        {
            pos = p;
            if (*q < *p) 
            {
                pos = q;
            }
            if (pos != p) 
            {
                tmp = *pos;
                *pos = *p;
                *p = tmp;
            }
        }
    }
    
    return 0;
}

int print_array(int *a, int len)
{
    int *p;
    for (p = a; p - a < len; p++) 
    {
        printf("a[%d] = %d\n", p-a, *p);
    }
    
    return 0;
}

int init_array(int *a, int len, int max)
{
    int *p;

    srand(time(NULL));
    for (p = a; p - a < len; p++) 
    {
        *p = rand() % max;
    }
    
    return 0;
}
