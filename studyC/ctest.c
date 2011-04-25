#include <stdio.h>

int main(int argc, const char *argv[])
{
    int num, i;
    int times = 0;
    int mask = 0x01;

    printf("Input the number:\n");
    scanf("%d", &num);

    for (i = 0; i < sizeof(int) * 8; i++, mask <<= 1) 
    {
        times += (num & mask) != 0 ? 1 : 0;
    }
    printf("%d\n", times);

    return 0;
}
