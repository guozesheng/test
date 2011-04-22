/*
类型转换--typeconv.c
*/

#include <stdio.h>

int main(void)
{
    int i = 0X1ffff;
    printf("%hx\n", (unsigned short)i);
    printf("%hx\n", i);
    printf("%d\n", i);
    return 0;
}
