#include <stdio.h>

int str_to_int(char *str);
int int_to_str(char *str, int num);

int main(int argc, const char *argv[])
{
    char a[100];
    char b[100];
    int num;

    printf("Please input the num:\n");
    fgets(a, 100, stdin);

    num = str_to_int(a);
    printf("%d\n", num);

    int_to_str(b, num);
    printf("%s\n", b);
    
    return 0;
}

int int_to_str(char *str, int num)
{
    int i = 0;
    int tmp = num;

    while (tmp) 
    {
        tmp = tmp / 10;
        i++;
    }
    *(str + i) = '\0';

    while (num) 
    {
        i--;
        *(str + i) = num % 10 + '0';
        num = num / 10;
    }
    
    return 0;
}

int str_to_int(char *str)
{
    int num = 0;
    int i = 0;
    int flag = 0;

    if (*str == '-') 
    {
        i++;
        flag = 1;
    }

    num = *(str + i) - '0';
    i++;

    while (*(str + i) >= '0' && *(str + i) <= '9') 
    {
        num = num * 10 + *(str + i) - '0';
        i++;
    }

    if (flag) 
    {
        num = 0 - num;
    }

    return num;
}
