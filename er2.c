#include <stdio.h>

int main(int argc, const char *argv[])
{
    int num, i, a[32];

    printf("Please input a number:");
    scanf("%d", &num);

    for (i = 0; i < 32; i++) 
    {
        a[i] = num & 0x01;
        num >>= 1;
    }
    while (i--) 
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
