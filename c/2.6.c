/*
变量打印
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    double x;
    x = 25 / 2;
    printf("int 25/2 = %d, double 25/2 = %f, x = %f\n", 25/2, 25.0/2, x);
    return 0;
}

/*
若将第10行改为: x = 25.0 / 2; 则最终x = 12.500000;
*/
