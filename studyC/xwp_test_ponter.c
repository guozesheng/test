#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a;
    int *p;
    
    p = &a;
    *p = 0x500;
    a = (int)(*(&p));
    if (a == (int)p) 
    {
        printf("equal!\n");
    }
    else 
    {
        printf("not equal!\n");
    }

    a = (int)(&(*p));
    if (a == (int)p) 
    {
        printf("equal!\n");
    }
    else 
    {
        printf("not equal!\n");
    }

    return 0;
}
