/*
 * switch 实现一个函数
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int num1, num2;

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    switch (*argv[2])
    {
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            printf("%d / %d = %d\n", num1, num2, num1 / num2);
            break;
        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        default:
            ;
            break;
    }
    

    return 0;
}
