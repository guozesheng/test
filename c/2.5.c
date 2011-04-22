/*
全局变量
*/

#include <stdio.h>

int a;

int main(int argc, char *argv[])
{
    a += 1;
    printf("%p, %d\n", &a, a);
    return 0;
}

/*
%p 输出一个指针的地址
*/
