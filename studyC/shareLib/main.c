#include <stdio.h>
#include "test.h"

int main(int argc, const char *argv[])
{
    int sum;

    sum = test_print();

    printf("%d\n", sum);
    printf("Hello, world!\n");
    
    return 0;
}
