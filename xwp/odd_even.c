#include <stdio.h>

#define N   10

void odd_even(int *a, int max);

int main(int argc, const char *argv[])
{
    //int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int a[N] = {0};
    int i;

    printf("Please input %d numbers for the array:\n", N);

    for (i = 0; i < N; i++) 
    {
        scanf("%d", &a[i]);
    }

    odd_even(a, N);

    printf("\nThe sorted array is:\n");
    for (i = 0; i < N; i++) 
    {
        printf("%4d", a[i]);
    }

    printf("\n");
    return 0;
}

void odd_even(int *a, int max)
{
    int i = 0;
    int temp;
    max--;
    while (i != max) 
    {
        while ((*(a + i) % 2) && i < max)    //odd
        {
            i++;
        }
        while (!(*(a + max) % 2) && max > i) //even
        {
            max--;
        }
        temp = *(a+i);
        *(a+i) = *(a+max);
        *(a+max) = temp;
    }
}
