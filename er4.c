#include <stdio.h>

int main(int argc, const char *argv[])
{
    int num;
    int i = sizeof(int) * 8 - 2;

    printf("Please input a number:");
    scanf("%d", &num);

    if (num < 0) 
    {
        num = -num;
        printf("1");
    }
    else 
    {
        printf("0");
    }

    while (i--) 
    {
        printf("%d", num>>i & 0x01);
    }
    printf("\n");
    return 0;
}
