/*
变量的格式化打印
*/

#include <stdio.h>

int foo(int a)
{
    printf("%d\n", a);
    return 0;
}

int main(int argc, char *argv[])
{
    printf("%d\n", 100);
    //printf("%d\n", 200.0);
    foo(300.0);
    return 0;
}

/*
2.1.c:16: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘double’
*/
