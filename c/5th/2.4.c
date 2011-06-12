/*
 * my_strcpy()
 */

#include <stdio.h>

char *my_strcpy(char *dest, char *src);

int main(int argc, const char *argv[])
{
    char str1[] = "Hello, world!";
    char str2[96];

    my_strcpy(str2, str1);

    printf("%s\n", str2);
    
    return 0;
}

char *my_strcpy(char *dest, char *src)
{
    while (*src) 
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    
    return dest;
}
