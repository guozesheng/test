#include <stdio.h>

int main(int argc, const char *argv[])
{
    int num;
    int i = sizeof(int) * 8 - 4;
    char str_h[16] = "0123456789ABCDEF";

    printf("Please input a numer:");
    scanf("%d", &num);

    while (i -= 4) 
    {
        printf("%c", str_h[num>>i&0x0f]);
    }
    printf("%c", str_h[num>>i&0x0f]);

    printf("\n");

    return 0;
}
