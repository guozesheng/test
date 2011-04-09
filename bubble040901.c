#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void initArray(int p[], int n);
void printArray(int p[], int n);
void bubbleArray(int p[], int n);
void bubbleArray2(int p[], int n);
void quickSort(int p[], int x, int y);

int main(int argc, const char *argv[])
{
    int array[N] = {2, 3, 8, 6, 5};

    //initArray(array, N);
    printArray(array, N);
    printf("\nPress Enter to start sort:\n");
    getchar();

    //bubbleArray(array, N);
    //bubbleArray2(array, N); //Wrong!!
    quickSort(array, 0, N-1);
    printf("\nSorted! Press Enter to print\n");
    getchar();

    printArray(array, N);
    
    printf("\n");
    return 0;
}

void initArray(int p[], int n)
{
    int i;
    
    srand(time(NULL));

    for (i = 0; i < n; i++) 
    {
        p[i] = rand() % N;
    }
}

void printArray(int p[], int n)
{
    int i;

    for (i = 0; i < n; i++) 
    {
        printf("%7d", p[i]);
        if (i % 10 == 9) 
        {
            printf("\n");
        }
    }
    printf("\n");
}

void bubbleArray(int p[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++) 
    {
        for (j = i; j < n; j++) 
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

void bubbleArray2(int p[], int n)
{
    int i, j, temp, k;

    for (i = 0; i < n - 1; i++) 
    {
        for (j = i, k = i; j < n; j++) 
        {
            if (p[k] > p[j]) 
            {
                k = j;
            }
        }
        if (p[k] > p[j]) 
        {
            temp = p[k];
            p[k] = p[j];
            p[j] = temp;
        }
    }
}

void quickSort(int p[], int x, int y)
{
    int i = x;
    int j = y;
    int mid = p[(x+y) / 2];
    int temp;

    while (i <= j) 
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
        quickSort(p, x, j);
    }
    if (y > i) 
    {
        quickSort(p, i, y);
    }
}
