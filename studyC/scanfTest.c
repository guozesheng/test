#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char temp;
    int num;
    int i = 0;

    if ((fp = fopen("a.text", "r")) == NULL)
    {
        return 0;
    }
    while (fscanf(fp, "%d\t%c", &num, &temp) != EOF) // fscanf(fp, "%d%c", &num, &temp)
    {
        printf("%d, %c\n", num, temp);
        if (i++ == 20) 
        {
            printf("i == 20\n");
            break;
        }
    }
    return 0;
}
