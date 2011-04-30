#include <stdio.h>
#include <string.h>

int str_common(char *str1, char *str2);

int main(int argc, const char *argv[])
{
    char str1[50];
    char str2[50];
    int sum;

    printf("Please input the str1:\n");
    fgets(str1, 50, stdin);
    printf("Please input the str2:\n");
    fgets(str2, 50, stdin);

    sum = str_common(str1, str2);
    
    printf("%d\n", sum);

    return 0;
}

int str_common(char *str1, char *str2)
{
    int sum = 0;
    int tsum = 0;
    int i, j;
    char *p1;
    char *p2;

    for (i = 0; i < strlen(str1) - 1; i++) 
    {
        p1 = str1 + i;
        p2 = str2;
        for (j = 0, p2 = str2; j < strlen(str2) - 1; j++, p2 = str2 + j, tsum = 0) 
        {
            while (*p1 == *p2) 
            {
                p1++;
                p2++;
                tsum++;
            }
            if (tsum > sum) 
            {
                sum = tsum;
            }
        }
    }
    
    return sum;
}
