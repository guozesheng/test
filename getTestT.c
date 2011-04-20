#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char *sHello = "Hello, world!";
    char sRead[20], sR2[20];
    char cR;
    FILE *fp;
    int i = 0;

    fp = fopen("a.text", "w+");
    if (fp == NULL) 
    {
        perror("feopen:");
    }
    fputs(sHello, fp);
    rewind(fp);
    fgets(sRead, 8, fp);
    cR =  fgetc(fp);

    while (sHello[i] != '\0') 
    {
        fputc(sHello[i++], fp);
    }

    rewind(fp);
    //i = 0;
    //do 
    //{
        //sR2[i] = fgetc(fp);
    //} while (sR2[i++] != EOF);
    //sR2[--i] = '\0';
    
    fclose(fp);

    printf("sRead:\t%s\n", sRead);
    printf("cR:\t%c\n", cR);
    //printf("sR2:\t%s\n", sR2);
    return 0;
}
