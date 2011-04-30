#include <stdio.h>

char check_ch(const char *str);

int main(int argc, const char *argv[])
{
    char str[] = "abaccedff";
    char c;

    c = check_ch(str);

    printf("%c\n", c);
    
    return 0;
}

char check_ch(const char *str)
{
    char ch;
    char *p = str;

    for (ch = *str; *str != '\0'; str++, p = str) 
    {
        if (*p == '\0') 
        {
            break;
        }
        else if (*p == ch) 
        {
            continue;
        }
    }

    return ch;
}
