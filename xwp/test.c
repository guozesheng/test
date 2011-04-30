#include <stdio.h>

int main(int argc, char *argv[])
{
    char **p = argv;
    printf("%x\n", (unsigned int)*p);
    (*p)++;
    printf("%x\n", (unsigned int)*p);

    //char str[5][10] = {{"asdf"}, {"qqqqq"}};
    //char (*p)[10];
    //p = str;
    //printf("%c\n", **p);
    return 0;
}
