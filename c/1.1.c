/*
 * 函数的定义/声明
 */

#include <stdio.h>

int goo(int d, int e, int f)
{
    int g;
    g = d + e;
    printf("g: %d\n", g);
    return f;
}

int foo()
{
    return 0;
}

int swap(int a, int b);

int main(int argc, const char *argv[])
{
    int x, y;
    x = -1;
    y = 2;
    printf("hell\n", x, y);
    swap(x, y);
    printf("f: %d\n", goo(2, 3, 4));
    printf("foo: %d\n", foo(1, 2, 34, 5));
    return 0;
}

int swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    return 0;
}
