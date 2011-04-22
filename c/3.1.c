/*
 * if / else 分支结构
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    char c;
    c = 128;

    if (c == 128) 
    {
        printf("Hello\n");
    }
    else
        printf("World\n");
    printf("%d\n", c);
    return 0;
}
