#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a[10] = {3, 1, 2, 0, 8, 3, 4, 5, 7, 9};
    int i, j, tmp;

/*
    for (i = 0; i < 10; i++) 
    {
        for (j = i; j < 10; j++) 
        {
            if (a[i] > a[j]) 
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
//*/

    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 9 - i; j++) 
        {
            if (a[j] > a[j+1]) 
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    for (i = 0; i < 10; i++) 
    {
        printf("%d", a[i]);
    }

    printf("\n");
    return 0;
}
