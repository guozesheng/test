#include <stdio.h>
#include <string.h>

int str_exchang(char *str);

int main(int argc, const char *argv[])
{
    char str[] = "Hello, world!";

    printf("Befor exchang:\n");
    printf("%s\n", str);

    str_exchang(str);

    printf("After exchang:\n");
    printf("%s\n", str);

    return 0;
}

int str_exchang(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;
    char tmp;

    while (start < end) 
    {
        tmp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = tmp;
        start ++;
        end--;
    }
    
    return 0;
}
