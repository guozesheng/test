#include <stdio.h>

void initArray(int *p, int len);
void printArray(int *p, int len);
void yusurf(int *p, int len, int n);

int main(int argc, const char *argv[])
{
    int a[10];
    initArray(a, 10);
    printArray(a, 10);
    printf("\n");

    yusurf(a, 10, 3);

    printf("\n");
    return 0;
}

void initArray(int *p, int len)
{
    int i;
    for (i = 0; i < len; i++, p++) 
    {
        *p = i + 1;
    }
}

void printArray(int *p, int len)
{
    int i;
    for (i = 0; i < len; i++) 
    {
        printf("%d, ", *p++);
    }
}

void yusurf(int *p, int len, int n)
{
    int flag, i;
    int *pt = p;

    for (flag = len, i = 1; flag > 0; i++) 
    {
        printf("%5d", *pt);
        if (i % n == 0) 
        {
            *pt = 0;
            printf("(out)\n");
            flag--;
        }
        do 
        {
            pt++;
            pt = pt==p+len ? p : pt;
        } while (flag > 0  &&  *pt == 0);
    }
}
