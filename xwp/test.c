#include <stdio.h>

int main(int argc, char *argv[])
{
    int count = 0;

    int i = 0;
    for (i = 31; i > 0; i--) 
    {
        if ((8 & (0x01<<i)) > 0) 
        {
            count ++;
        }
    }
    printf("%d\n", count);

    //char **p = argv;
    //printf("%x\n", (unsigned int)*p);
    //(*p)++;
    //printf("%x\n", (unsigned int)*p);

    ////char str[5][10] = {{"asdf"}, {"qqqqq"}};
    ////char (*p)[10];
    ////p = str;
    ////printf("%c\n", **p);
    return 0;
}
