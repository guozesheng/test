/*
	二维数组的转置
*/

#include<stdio.h>

void main()
{
    int a[2][3] = {{1, 2, 3},{4, 5, 6}};
    int b[3][2];
    int i, j;
    
    printf("Array A:\n");
    for (i=0; i<2; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%3d", a[i][j]);
            b[j][i] = a[i][j];
        }
        printf("\n");
    }
        
    printf("\nArray B:\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<2; j++)
            printf("%3d", b[i][j]);
        printf("\n");
    }
}
