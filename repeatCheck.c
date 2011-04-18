#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initArray(int *p, int len);
void printArray(int *p, int len);
void checkArray(int *p, int len);

int main(int argc, const char *argv[])
{
    int a[20];
    initArray(a, 20);
    printArray(a, 20);
    checkArray(a, 20);
    printArray(a, 20);
    
    return 0;
}

void initArray(int *p, int len)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < len; i++, p++) 
    {
        *p = rand() % 15;
    }
}

void printArray(int *p, int len)
{
    int i;
    for (i = 0; i < len; i++, p++) 
    {
        if (*p != -1) 
        {
            printf("%3d", *p);
        }
    }
    printf("\n");
}

void checkArray(int *p, int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++) 
    {
        if (*(p+i) != -1)
        {
            for (j = i + 1; j < len; j++) 
            {
                if (*(p+i) == *(p+j)) 
                {
                    *(p+j) = -1;
                }
            }
        }
    }
}
