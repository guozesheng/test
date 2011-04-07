#include <stdio.h>

int main(int argc, const char *argv[])
{
    int num;
    int i = 28;
    unsigned int mask = 0x0f;
    char str_h[16] = "0123456789ABCDEF";

    printf("Please input a numer:");
    scanf("%d", &num);

    while (i -= 4) 
    {
        printf("%c", str_h[num>>i&mask]);
    }
    printf("%c", str_h[num>>i&mask]);

    printf("\n");

    return 0;
}
