#include <stdio.h>

int initArray(int p[], int n);
int printArray(int p[], int n);

int main(int argc, const char *argv[])
{
    int a[100];
    initArray(a, 100);
    printArray(a, 100);

    printf("\n");
    return 0;
}

int initArray(int p[], int n)
{
    int i;
    for (i = 0; i < n; i++) 
    {
        p[i] = i + 1;
    }
    return 0;
}

int printArray(int p[], int n)
{
    int i;
    for (i = 0; i < n; i++) 
    {
        printf("%5d", p[i]);
    }
    return 0;
}
