#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp_src, *fp_dest;
    char temp[4096];

    if ((fp_src = fopen("a.text", "r")) == NULL)
    {
        perror("fopen a.text");
        exit(1);
    }
    if ((fp_dest = fopen("b.text", "w+")) == NULL) 
    {
        perror("fopen b.text");
        exit(1);
    }

    while (!feof(fp_src)) 
    {
        fread(temp, 1, 1, fp_src);
        fwrite(temp, 1, 1, fp_dest);
    }
    
    fclose(fp_src);
    fclose(fp_dest);
    return 0;
}
