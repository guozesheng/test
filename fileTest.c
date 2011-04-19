#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp, *p;
    char *str = "Hello, world!";
    char strRead[100];
    
    fp = fopen("a.text", "wr");
    if (fp == NULL) 
    {
        perror("open:");
        exit(0);
    }
    p = fp;
    fprintf(fp, "%s\n", str);
    fprintf(p, "test");
    //fscanf(p, "%s", strRead);
    fclose(fp);

    //printf(":%s:\n", strRead);

    return 0;
}
