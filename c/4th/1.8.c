/*
 * demo helloworld application
 */

#include <stdio.h>

char str[] = "Hello, world!";
char *pstr = "HELLO, WORLD!";
char *pstr2 = 0;

int main(int argc, const char *argv[])
{
    int i;

    printf("str = %s\n", str);
    printf("pstr = %s\n", pstr);

    pstr = str;
    pstr[1] = '1';
    *(pstr++) = '2';
    *(pstr + 1) = '3';
    printf("2 pstr = %s\n", pstr);
    str[1] = '-';
    printf("2 str = %s, pstr = %s\n", str, pstr);

    pstr = str;
    *(pstr + 1) = '9';
    for (i = 0; i < 24; i++) 
    {
        printf("pstr + %d = '%c'(=0x%x)\n", i, *(pstr + i), *(pstr + i));
    }
    printf("str = %s, pstr = %s\n", str, pstr);

    return 0;
}
