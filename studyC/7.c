/*
用二维数组实现选择法排序
*/

#include <stdio.h>

void main()
{
    void pri(int *x, int ni, int nj);
    void sort(int (*x)[10], int nj);

    int a[2][10] = {3, 6, 7, 9, 5, 4, 2, 1, 4, 7};
    sort(a, 10);
    pri(*a, 2, 10);
}

void pri(int *x, int ni, int nj)
{
    int i = ni * nj;
    while (i--)
    {
        printf("%4d", *x++);
        if (i % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

void sort(int (*x)[10], int nj)
{
    int i, j, temp;
    
    for (i=0; i<nj; i++)
    {
        *(*(x+1)+i) = *(*x+i); 
        for (j=i+1; j<nj; j++)
        {
            if (*(*(x+1)+i) > *(*x+j))
            {
                temp = *(*(x+1)+i);
                *(*(x+1)+i) = *(*x+j);
                *(*x+j) = temp;
            }
        }
    }
}

/*
    占用空间较大，只是为了复习指针相关内容
*/
