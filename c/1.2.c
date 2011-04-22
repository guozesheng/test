/*
 * 自定义函数应用
 */

#include <stdio.h>

int add(int a, int b);

int sub(int a, int b);

int main(int argc, const char *argv[])
{
    int ret;
    int a = 100;
    int b = 200;

    ret = add(a, b);
    printf("add: %d\n", ret);

    ret = sub(a, b);
    printf("sub: %d\n", ret);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}
