#include <stdio.h>

int main(int argc, const char *argv[])
{
    char str[20] = "This is a C world!";
    char *p = str;
    
    while (*p != '\0') 
    {
        printf("%c", *p++);
    }
    printf("\n");

    //p += sizeof(str);

    while (p-- > str) 
    {
        printf("%c", *p);
    }

    printf("\n");
    return 0;
}
