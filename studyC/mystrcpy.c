#include <stdio.h>

char *mystrcopy(char *dest, const char *src);

int main(int argc, const char *argv[])
{
    char src[] = "Hello, world!";
    char dest[30];
    char *p;

    p = mystrcopy(dest, src);

    printf("%s\n", src);
    printf("%s\n", dest);
    printf("%s\n", p);
    
    return 0;
}

char *mystrcopy(char *dest, const char *src)
{
    char *head = dest;
    
    while (*src != '\0') 
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    
    return head;
}
