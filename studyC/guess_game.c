#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int init_num(char *str, int len);
int user_input(char *str, int len);
int chck_num(char *src, char *usr, int len);

int main(int argc, const char *argv[])
{
    int len = 4;
    char src_num[5];
    char usr_num[4096];
    int flag = 0;

    init_num(src_num, len);

    while (flag == 0) 
    {
        flag = user_input(usr_num, len);
        if (flag == 1) 
        {
            flag = chck_num(src_num, usr_num, len);
        }
    }

    if (flag == -1) 
    {
        printf("%s\n", src_num);
    }

    return 0;
}

int chck_num(char *src, char *usr, int len) // win: return 1, fail: return 0
{
    int flag[2] = {0};    // flag[0]: A  flag[1]: B
    int i, j;

    for (i = 0; i < len; i++) 
    {
        for (j = 0; j < len; j++) 
        {
            if (*(src + i) == *(usr + j)) 
            {
                if (i == j) 
                {
                    flag[0]++;
                }
                else 
                {
                    flag[1]++;
                }
            }
        }
    }

    if (!flag[0] && !flag[1]) 
    {
        printf("0000\n");
    }
    if (flag[0] == 4) 
    {
        printf("YOU WIN!!\n");
        return 1;
    }
    while (flag[0]--) 
    {
        printf("A");
    }
    while (flag[1]--) 
    {
        printf("B");
    }
    
    printf("\n");
    return 0;
}

int user_input(char *str, int len)  // normal: return 1; abnormal: return 0; give up: return -1
{
    int i, j;

    printf("Please input:\n");
    fgets(str, 4096, stdin);

    if (*(str + len) == '\n' && (*(str + len-1) >= 0x30 && *(str + len-1) <= 0x39) )   // legal number
    {
        for (i = 0; i < len - 1; i++) 
        {
            if (*(str + i) < 0x30 || *(str + i) > 0x39)   // illegal number
            {
                return 0;
            }
            for (j = i + 1; j < len; j++)       // check repeat number
            {
                if (*(str + i) == *(str + j))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    if (strcmp(str, "I GIVE UP\n") == 0) 
    {
        return -1;
    }
    
    return 0;
}

int init_num(char *str, int len)
{
    int i, j;
    int a[4];

    srand(time(NULL));

    a[0] = rand() % 9 + 1;

    for (i = 1; i < len; i++) 
    {
        a[i] = rand() % 10;
        for (j = 0; j < i; j++) 
        {
            while (a[j] == a[i]) 
            {
                a[i] = rand() % 10;
                j = 0;
            }
        }
    }

    for (i = 0; i < len; i++) 
    {
        *(str + i) = a[i] + 0x30;
    }
    *(str + 4) = '\0';

    printf("%s\n", str); //temp
    return 0;
}
