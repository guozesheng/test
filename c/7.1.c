#include <stdio.h>

int test_endian(void);

union node
{
    int a;
    char b;
};

int main(int argc, const char *argv[])
{
    test_endian();   

    return 0;
}

int test_endian(void)
{
    union node u;
    u.a = 0x12345678;
    if (u.b == 0x78) 
    {
        printf("little endian\n");
    }
    else 
    {
        printf("big endian\n");
    }
    return 0;
}
