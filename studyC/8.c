/*
指向函数的指针
*/

#include <stdio.h>

void main()
{
    int max(int x, int y);
    
    int a, b, c;
    int (*p)(int, int);
    p = max;
    
    printf("请输入两个数字:");
    scanf("%d, %d", &a, &b);
    
    c = (*p)(a, b);
    
    printf("%d, %d, max:%d\n", a, b, c);
}

int max(int x, int y)
{
    int z;
    if (x > y)
        z = x;
    else 
        z = y;
    return (z);
}
