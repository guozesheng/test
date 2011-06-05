#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 5;

    const int *p = &a;

    a = 6;  /////////

    printf("%d\n", *p);
    
    return 0;
}
