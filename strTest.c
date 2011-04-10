#include <stdio.h>
#include <string.h>

int chrfind(const char *p, const char *chr);

int main(int argc, const char *argv[])
{
    char s[] = "Good morning! Changchun!";
    int n;

    n = chrfind(s, "mor");
    printf("%d\n", n);

    return 0;
}

int chrfind(const char *p, const char *chr)
{
    int j;
    int i = 0;
    while (*p != '\0') 
    {
        i++;
        j = 0;
        while (*(p+j) == *(chr+j)) 
        {
            j++;
            if (*(chr+j) == '\0') 
            {
                return i;
            }
        }
        p++;
    }
    return 0;
}
