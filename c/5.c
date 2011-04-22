/*
自定义函数应用
*/

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main(int argc, char *argv[])
{
    int a = 500, b = 200;
    printf("add=%d\n", add(a, b));
    printf("sub=%d\n", sub(a, b));
    return 0;
}
