#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N   10

void initArray(int *p, int len, int max);
void printArray(int *p, int len);
void bubbleArray(int *p, int len);
void selectArray(int *p, int len);
void quickArray(int *p, int i, int j);

int main(int argc, const char *argv[])
{
    int a[N][N] = {{2, 4, 6}};
    a[1][0] = 3;

    //printf("%d, %d, %d\n", a[0][0], a[0][1], a[0][2]);

    initArray(a[0], N*N, N*N);
    printArray(a[0], N*N);

    //printf("Bubble Sort:\n");
    //bubbleArray(a[0], N*N);
    //printArray(a[0], N*N);

    //printf("Select Sort:\n");
    //selectArray(a[0], N*N);
    //printArray(a[0], N*N);

    printf("Quick Sort:\n");
    quickArray(a[0], 0, N*N-1);
    printArray(a[0], N*N);

    return 0;
}

void initArray(int *p, int len, int max)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < len; i++, p++) 
    {
        *p = rand() % (max);
    }
    //printf("%d\n", *p);
    //p++;
    //printf("%d\n", *p);
}

void printArray(int *p, int len)
{
    int i;
    for (i = 0; i < len; i++, p++) 
    {
        printf("%5d", *p);
        if (i % 10 == 9) 
        {
            printf("\n");
        }
    }
    printf("\n");
}

void bubbleArray(int *p, int len)
{
    int i, j, temp;
    int *pt = p;
    for (i = 0; i < len; i++) 
    {
        for (j = 0, pt = p; j < len - i - 1; j++, pt++) 
        {
            if (*pt > *(pt+1)) 
            {
                temp = *pt;
                *pt = *(pt+1);
                *(pt+1) = temp;
            }
        }
    }
}

void selectArray(int *p, int len)
{
    int i, j, temp;
    int *pt = p;

    for (i = 0; i < len; i++, p++, pt = p) 
    {
        for (j = i; j < len; j++, pt++) 
        {
            if (*p > *pt) 
            {
                temp = *p;
                *p = *pt;
                *pt = temp;
            }
        }
    }
}

void quickArray(int *p, int i, int j)
{
    int temp;
    int x = i;
    //j--;
    int y = j;
    int mid = *(p + y/2);

    while (x <= y) 
    {
        while (*(p+x) < mid) 
        {
            x++;
        }
        while (*(p+y) > mid) 
        {
            y--;
        }
        if (x <= y) 
        {
            temp = *(p+x);
            *(p+x) = *(p+y);
            *(p+y) = temp;
            x++;
            y--;
        }
    }
    if (x < j) 
    {
        quickArray(p+x, x, j);
    }
    if (y > i) 
    {
        quickArray(p+i, i, y);
    }
}












