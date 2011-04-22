/*
 * Nature of the array
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a[5] = {1, 2};
    printf("%p\n", a);
    printf("%p\n", &a);
    printf("%p\n", &a[0]);

    return 0;
}
