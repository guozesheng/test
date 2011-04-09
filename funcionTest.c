#include <stdio.h>

int  add(int a, int b);
int  sub(int a, int b);
int  mul(int a, int b);
int  div(int a, int b);

int main(int argc, const char *argv[])
{
    int num1, num2, res;
    char c;

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);
    c = *argv[2];

    switch(c)
    {
        case '+':
            res = add(num1, num2);;
            break;
        case '-':
            res = sub(num1, num2);
            break;
        case '*':
            res = mul(num1, num2);
            break;
        case '/':
            res = div(num1, num2);
            break;
        default:
            break;
    }
    
    printf("%d %c %d = %d\n", num1, c, num2, res);
    return 0;
}

int  add(int a, int b)
{
    return (a + b);
}

int  sub(int a, int b)
{
    return (a - b);
}

int  mul(int a, int b)
{
    return (a * b);
}

int  div(int a, int b)
{
    return (a / b);
}
