#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    //char c;
    int c;

    if ((fp = fopen("a.text", "r")) == NULL) 
    {
        printf("Can't read!\n");
        return 0;
    }

    while ((c = getc(fp)) != EOF) 
    {
        printf("%d\n", c);
    }
    printf("%d\n", getc(fp));
    return 0;
}
