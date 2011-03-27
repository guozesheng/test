#include <stdio.h>
#include <time.h>

void pri(int times, char c);

int main(int argc, const char *argv[])
{
    int i;
    int bar_longth = 60;
    int wait_time = 11;
    int wait_times = bar_longth / wait_time;

    for (i = 0; i < wait_time; i++) 
    {
        int j = i;
        int k = wait_time - i;
        int percent = i*100 / wait_time;

        printf("\r[");
        while (j--) 
        {
            pri(wait_times, '=');
        }
        printf(">");
        while (k--) 
        {
            pri(wait_times, ' ');
        }
        printf("]%d%%", percent);
        fflush(stdout);

        sleep(1);
    }
    printf("\n");
    return 0;
}

void state_pri(int i, int times_i)
{
    printf("\r");
    while (i--) 
    {
        pri(times_i, '=');
    }
}

void pri(int times, char c)
{
    while (times--) 
    {
        printf("%c", c);
    }
}
