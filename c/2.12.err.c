/*
打印变量的地址
*/

#include <stdio.h>
#include "2.12.add.c"

#define MAX 5
#define MIN 0

int globle_var = 0X1234;
const int const_num = 0X9999;
int add(int, int);
int a_out = 10;
int b_out = 20;

int main(int argc, char *argv[])
{
    int a = 100;
    int b = 200;
    int *p = 0X804972c;
    printf("<main> address a = 0X%x \n", &a);
    printf("<main> address b = 0X%x \n", &b);
    printf("<main> address a_out 0X%x \n", &a_out);
    printf("<main> address b_out 0X%x \n", &b_out);
    add(a, b);
    *p = 123;
    add(a, b);
    printf("sta_a = %d \n", *p);
    return 0;
}
