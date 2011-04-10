/*
	前后顛倒数组
*/

#include <stdio.h>

void main()
{
    void pri(int *pa, int n);
    void inv(int *pa, int n);

    int a[10] = {3, 6, 7, 9, 5, 4, 2, 1, 4, 7};
    
    pri(a, 10);
    inv(a, 10);
    pri(a, 10);
}

void pri(int *pa, int n)
{
	while (n--)
	{
		printf("%4d", *pa++);
	}
	printf("\n");
}

void inv(int *pa, int n)
{
    int *pt, temp, m;
    m = (n - 1) / 2;
    pt = pa + n - 1;
    
    while (m--)
    {
        temp = *pa;
        *pa++ = *pt;
        *pt-- = temp;
    }
}

/*
    注意程序的第32行，两个都是指针，故应没有*号
*/
