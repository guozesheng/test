#include <stdio.h>

typedef void (*callback_t)(void *);

void repeat_three_times(callback_t f, void *para);
void say_hello(void *str);
void count_number(void *num);

int main(int argc, const char *argv[])
{
    repeat_three_times(say_hello, "Guys");
    repeat_three_times(count_number, (void *)4);
    
    return 0;
}

void count_number(void *num)
{
    int i;
    for (i = 0; i < (int)num; i++) 
    {
        printf("%d ", i);
    }
    printf("\n");
}

void say_hello(void *str)
{
    printf("Hello %s\n", (const char *)str);
}

void repeat_three_times(callback_t f, void *para)
{
    f(para);
    f(para);
    f(para);
}
