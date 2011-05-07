#include <stdio.h>

int main(int argc, const char *argv[])
{
    struct st_t
    {
        int status;
        short *pdata;
        char errstr[32];
    } ;

    struct st_t st[16];
    char *p = (char *)(st[2].errstr + 32);
    printf("%d\n", (p - (char *)(st)));

    return 0;
}
