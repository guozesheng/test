/*
 * Comput the days of a year by the 'year', 'mon', 'day'.
 */

#include <stdio.h>

int dayOfYear(int year, int mon, int day);

int day_tab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(int argc, const char *argv[])
{
    int y, m, d;
    printf("Please input the Year, Mon, Day:\n");
    scanf("%d, %d, %d", &y, &m, &d);
    dayOfYear(y, m, d);
    printf("%d-%d is %d of year %d!\n", m, d, dayOfYear(y, m, d), y);

    return 0;
}

int dayOfYear(int year, int mon, int day)
{
    int is_leapyear, j;
    is_leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if ((is_leapyear == 0) && (mon == 2) && (day >= 29)) 
    {
        printf("%d out of range!\n", day);
        return -1;
    }
    for (j = 1; j < mon; j++) 
    {
        day += day_tab[is_leapyear][j];
    }
    return day;
}
