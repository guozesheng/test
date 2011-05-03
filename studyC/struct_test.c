#include <stdio.h>

struct 
{
    int num;
} a, b;

int main(int argc, const char *argv[])
{
    char c;
    c = '\'';
    a.num = 44;

    b = a;
    printf("%d\n", b.num);
    printf("C:%c\n", c);
    
    return 0;
}
