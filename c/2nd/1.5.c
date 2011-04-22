/*
 * get_put.c
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a, b, c;
    char buf[128];

    a = getchar();
    b = getc(stdin);
    printf("get a = %c, b = %c \n", a, b);
    c = getchar();
    printf("1:get c = %c(0x%x)\n", c, c);
    c = getchar();
    printf("2:get c = %c(0x%x)\n", c, c);

    fgets(buf, 5, stdin);
    printf("get buf str = %s\n", buf);

    c = ungetc(c, stdin);

    return 0;
}

/*
 * ungetc: return a charactor to the input stream
 */
