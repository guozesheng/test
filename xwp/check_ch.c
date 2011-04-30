#include <stdio.h>

char check_ch(const char *str);

int main(int argc, const char *argv[])
{
    char str[] = "abaccedff";
    char c;

    c = check_ch(str);

    if (c != '\0') 
    {
        printf("%c\n", c);
    }
    else 
    {
        printf("No match\n");
    }
    
    return 0;
}

char check_ch(const char *str)
{
    char ch;
    const char *p = str;

    for (; *str != '\0'; str++) 
    {
        ch = *str;
        p = str + 1;
        do 
        {
            if (*p == '\0') 
            {
                return ch;
            }
            else if (*p == ch) 
            {
                break;
            }
            p++;
        } while (1);
    }

    return '\0';
}
