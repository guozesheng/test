#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp, *fp2;
    char sHello[1024];
    int n = 0;

    if (((fp = fopen("a.text", "r")) == NULL) || ((fp2 = fopen("a2.text", "w+")) == NULL)) 
    {
        perror("fopen:");
        exit(1);
    }
    while (!feof(fp)) 
    {
        fread(&sHello[n], 1, 1, fp);
        n++;
    }
    n--;
    if (n != 0) 
    {
        sHello[n] = '\0';
        fwrite(sHello, 1, n, fp2);
    }

    fclose(fp);
    fclose(fp2);
    printf("%d\n", n);
    return 0;
}
