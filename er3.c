#include <stdio.h>

int main(int argc, const char *argv[])
{
    int num, i = 31;

    printf("Please input a number:");
    scanf("%d", &num);

    while (i--) 
    {
        printf("%d", num>>i & 0x01);
    }
    printf("\n");
    return 0;
}
