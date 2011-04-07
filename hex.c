#include <stdio.h>

void cov(int num);

int main(int argc, const char *argv[])
{
    int num;
    printf("Please input a numer:");
    scanf("%d", &num);

    cov(num);
    printf("\n");

    return 0;
}

void cov(int num)
{
    int tmp;

    if (num / 16) 
    {
        cov(num / 16);
    }
    tmp = num % 16;
    if (tmp <= 9) 
    {
        printf("%d", tmp);
    }
    else 
    {
        printf("%c", 'A' + tmp - 10);
    }
    
}
