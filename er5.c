#include <stdio.h>

int main(int argc, const char *argv[])
{
    int num, i = 32;
    unsigned int mask = 0x80000000;

    printf("Please input a number:");
    scanf("%d", &num);

    while (i--) 
    {
        //printf("%d", num>>i & 0x01);
        printf("%d", (num & mask) != 0 ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
    return 0;
}
