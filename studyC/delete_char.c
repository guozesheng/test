#include <stdio.h>

void delete_char(char *str, char ch);

int main(int argc, const char *argv[])
{
    char s[] = "Heljo, world!";

    printf("%s\n", s);

    delete_char(s, 'l');
    
    printf("%s\n", s);
    return 0;
}

void delete_char(char *str, char ch)
{
    char *ptr;

    for (; *str != '\0' ; str++) 
    {
        if (*str == ch) 
        {
            ptr = str;
            while (*ptr != '\0') 
            {
                *ptr = *(ptr + 1);
                ptr ++;
            }
        }
    }
}
