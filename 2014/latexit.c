#include <stdio.h>
#include <stdlib.h>

int mytest(void)
{
    printf("hell, world\n");
    return 0;
}

int subfun(void)
{
    atexit((void *)mytest);
    return 0;
}

int main(int argc, const char *argv[])
{
    subfun();

    printf("This is main function\n");
    
    return 0;
}

