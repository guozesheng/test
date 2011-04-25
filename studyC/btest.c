#include <stdio.h>
#include <string.h>

void find_letter(char *str, int len, char *ctr, int cen);

int main(int argc, const char *argv[])
{
    char str[100];
    char ctr[100];

    printf("Input the str;\n");
    scanf("%s", str);

    getchar();
    printf("Input the letter:\n");
    scanf("%s", ctr);

    find_letter(str, strlen(str), ctr, strlen(ctr));

    printf("\n");
    return 0;
}
void find_letter(char *str, int len, char *ctr, int cen)
{
    int i, j;
    int flag = 0;

    for (i = 0; i < len - cen; i++) 
    {
        if (str[i] == ctr[0]) 
        {
            for (j = 1, i++; j < cen; i++, j++) 
            {
                if (str[i] != ctr[j]) 
                {
                    break;
                }
            }
        }
        if (j == cen && j != 1) 
        {
            flag = 1;
            printf("%d\n", i-j);
            j = 1;
        }
    }
    if (!flag) 
    {
        printf("Havn't found!\n");
    }
}
