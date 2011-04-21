#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp, *fp2;
    char sHello[1024];
    int n;

    if (((fp = fopen("a.text", "r")) == NULL) || ((fp2 = fopen("a2.text", "w+")) == NULL)) 
    {
        perror("fopen:");
    }
    n = fread(sHello, 1, 1024, fp);
    if (n != 0) 
    {
        sHello[n] = '\0';
        fwrite(sHello, 1, n, fp2);
    }

    fclose(fp);
    fclose(fp2);
    return 0;
}
