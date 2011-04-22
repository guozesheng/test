/*
 * Delete the repeat number from the array
 */

#include <stdio.h>
#define N 15

int main(int argc, const char *argv[])
{
    int a[N] = {100, 11, 2, 13, 3, 11, 7, 8, 9, 7};
    int i, j, reallen = N;
    int k;
    printf("Befor delete the repeated number:\n");
    for (i = 0; i < N; i++) 
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    for (i = 0; i < reallen; i++) 
    {
        for (j = k = i + 1; j < reallen; j++) 
        {
            if (a[i] != a[j]) 
            {
                a[k++] = a[j];
            }
        }
        reallen = k;
    }
    printf("After delete the repeated number:\n");
    for (i = 0; i < reallen; i++) 
    {
        printf("a[%d]= %d\n", i, a[i]);
    }

    return 0;
}
