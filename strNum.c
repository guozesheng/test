#include <stdio.h>

int strToNum(char *p);

int main(int argc, const char *argv[])
{
    char s[] = "Today is molo219zz";
    printf("%s\n", s);
    printf("%d\n", strToNum(s));

    return 0;
}

int strToNum(char *p)
{
    int temp = 0;
    int tt = 10;

    if (*p >= 0x30  &&  *p <= 0x39) 
    {
        temp = temp + (*p-0x30);
    }
    p++;
    while (*p != '\0') 
    {
        if (*p >= 0x30  &&  *p <= 0x39) 
        {
            temp = temp * tt + (*p-0x30);
        }
        p++;
    }
    return temp;
}
