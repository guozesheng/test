/*
 * myprintf: variable argument lists
 */

#include <stdio.h>
#include <stdarg.h>

int  mymax(int fmt, ...);

int main(int argc, const char *argv[])
{
    int test = 123;
    
    test = mymax(2, 134, 456);
    printf("max 2 number is %d\n", test);
    test = mymax(3, 234, -299, 798);
    printf("max 3 number is %d\n", test);
    test = mymax(4, 234, 111, 908, 897);
    printf("max 4 number is %d\n", test);

    return 0;
}

int  mymax(int fmt, ...)
{
    va_list ap;
    int i, ival;
    int max = 0;

    va_start(ap, fmt);
    for (i = 0; i < fmt; i++) 
    {
        ival = va_arg(ap, int);
        printf("<mymax>%d\n", ival);
        if (ival > max) 
        {
            max = ival;
        }
    }
    va_end(ap);
    return max;
}
