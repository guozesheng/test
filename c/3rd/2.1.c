/*
 * the transpose of the two-dimensional array
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a[5][5] = {{11, 2, 5, 8, 1}, 
                   {1, 2, 5, 8, 5}, 
                   {5, 4, 2, 6, 11}, 
                   {66, 22, 13, 63, 1}, 
                   {4, 1, 54, 13, 56}};
    int temp, i, j;
    printf("Befor T array a:\n");
    for (i = 0; i < 5; i++) 
    {
        for (j = 0; j < 5; j++) 
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 5-1; i++) 
    {
        for (j = i + 1; j < 5; j++) 
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    printf("After T array a:\n");
    for (i = 0; i < 5; i++) 
    {
        for (j = 0; j < 5; j++) 
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
