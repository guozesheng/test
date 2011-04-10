/*
用指向函数的指针做函数参数
*/

#include <stdio.h>

void main()
{
    int max(int, int);
    int min(int, int);
    int add(int, int);
    void process(int, int, int (*fun)(int, int));
    
    int a, b;
    
    printf("请输入两个数字：");
    scanf("%d, %d", &a, &b);
    
    printf("最大的数字是：");
    process(a, b, max);
    printf("最小的数字是：");
    process(a, b, min);
    printf("两个数的和是：");
    process(a, b, add);
}

int max(int x, int y)
{
    if (x > y)
        return (x);
    else 
        return (y);
}

int min(int x, int y)
{
    if (x > y)
        return (y);
    else 
        return (x);
}

int add(int x, int y)
{
    return (x + y);
}

void process(int x, int y, int (*fun)(int, int))
{
    printf("%d\n", (*fun)(x, y));
}
