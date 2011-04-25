#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_array(int *p, int len, int max);
void sort_array(int *p, int len);
void print_array(int *p, int len);
void quick_sort(int *p, int x, int y);

int main(int argc, const char *argv[])
{
    int a[100];
    int max = 100;

    init_array(a, 100, max);
    
    print_array(a, 100);

    sort_array(a, 100);
    printf("\nNow is sorted by bubble:\n");
    print_array(a, 100);

    quick_sort(a, 0, 100);
    printf("\nNow is sorted by quick:\n");
    print_array(a, 100);
    
    return 0;
}

void quick_sort(int *p, int x, int y)
{
    int i = x;
    int j = y;
    int temp;
    int mid = p[(x+y) / 2];

    while (i < j) 
    {
        while (p[i] < mid) 
        {
            i++;
        }
        while (p[j] > mid) 
        {
            j--;
        }
        if (i <= j) 
        {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;

            i++;
            j--;
        }
    }

    if (x < j) 
    {
        quick_sort(p, x, j);
    }
    if (y > i) 
    {
        quick_sort(p, i, y);
    }
}

void print_array(int *p, int len)
{
    int i;
    for (i = 0; i < len; i++) 
    {
        printf("%5d", p[i]);
        if (i % 10 == 9) 
        {
            printf("\n");
        }
    }
}

void sort_array(int *p, int len)
{
    int i, j;
    int temp;

    for (i = 0; i < len - 1; i++) 
    {
        for (j = i; j < len; j++) 
        {
            if (p[i] > p[j]) 
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void init_array(int *p, int len, int max)
{
    int i;

    srand(time(NULL));

    for (i = 0; i < len; i++) 
    {
        *p++ = rand() % max;
    }
}
