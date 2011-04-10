/*
fputc和fgetc函数使用
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *fp;
    char ch, filename[10];
    scanf("%s", filename);
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    ch = getchar();
    ch = getchar();
        
    while (ch != '#')
    {
        fputc(ch, fp);
        putchar(ch);
        ch = getchar();
    }
    
    putchar(10);
    fclose(fp);
}
