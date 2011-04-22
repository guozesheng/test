#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    //int n = 0;

    if ((fp = fopen("a.text", "r")) == NULL) 
    {
        return 0;
    }
    printf("aa:%d\n", feof(fp));
    printf("bb:%d\n", feof(fp));
    //if (!feof(fp)) 
    //{
        //n = 1;
    //}
    fclose(fp);
    //printf("%d\n", n);
    return 0;
}
