#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[20] = "This is a C world!";
    char *p = str;
    char cStr[20];
    char *pc = cStr;
    
//*
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
//*/

/*
    for (p += sizeof(str); p >= str; p--) 
    {
        putchar(*p);
    }
//*/

    printf("\n");
    for (p = str; *p != '\0'; p++) 
    {
        if (*p != ' ') 
        {
            *pc++ = *p;
        }
    }
    *pc = '\0';

    puts(cStr);

/*
    for (p = str, pc = str; *p != '\0'; p++) 
    {
        if (*p != ' ') 
        {
            *pc++ = *p;
        }
    }
    *pc = '\0';
//*/
    for (p = str, pc = str; *pc != '\0'; p++, pc++) 
    {
        while (*pc == ' ') 
        {
            pc++;
        }
        if (p != pc) 
        {
            *p = *pc;
        }
    }
    *p = '\0';
    printf("len=%d: %s\n", strlen(str), str);

    printf("\n");
    return 0;
}
