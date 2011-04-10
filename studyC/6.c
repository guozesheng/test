/*
指针选择法排序
*/

#include <stdio.h>

void main()
{
    void pri(int *x, int n);
    void sort(int *x, int n);

    int a[10] = {3, 6, 7, 9, 5, 4, 2, 1, 4, 7};
    pri(a, 10);
    sort(a, 10);
    pri(a, 10);
}

void pri(int *x, int n)
{
    while (n--)
    {
        printf("%4d", *x++);
    }
    printf("\n");
}

void sort(int *x, int n)
{
    int i, j, temp;
    int *p;
    
    for (i = 0; i < n; i++)
    {
        p = x;
        for (j = i+1; j < n; j++)
        {
            if (*(p+i) > *(p+j))
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
}

/*
    对数组进行赋初值，得是在初始化的时候。
*/
