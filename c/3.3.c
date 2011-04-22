/*
 * 判断闰年
 */

#include <stdio.h>

int isLeepYear(int year);

int main(int argc, const char *argv[])
{
    int year;

    if (argc != 2) 
    {
        printf("You haven't input the year at the argc!\n");
        return 0;
    }

    year = atoi(argv[1]);

    if (isLeepYear(year)) 
    {
        printf("%d is leep year.\n", year);
    }
    else 
    {
        printf("%d is not leep year.\n", year);
    }

    printf("%d is %s leep year!\n", year, isLeepYear(year) ? "" : "not");

    return 0;
}

int isLeepYear(int year)
{
    if ((year % 4 == 0) && (year % 100 != 0)) 
    {
        return 1;
    }
    else if (year % 400 == 0) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


/*
 * int atoi(const char *nptr): Convert a string to an integer type.
 */
