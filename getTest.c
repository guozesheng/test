/*
 * getc() fgetc() fgets()
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char c, cf, cf2;
    char s[20];
    FILE *fp;
    
    fp = fopen("a.text", "a+");
    if (fp == NULL) 
    {
        perror("open");
        exit(0);
    }
    cf = getc(fp);
    cf2 = fgetc(fp);
    c = getc(stdin);
    fgets(s, 3, fp);
    putc('a', stdout);
    printf("%c\n", c);
    printf("%c\n", cf);
    printf("%c\n", cf2);
    printf("%s\n", s);
    return 0;
}
