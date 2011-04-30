#include <stdio.h>
#include <string.h>

int my_strcmp(char *dest, char (*src)[10], int num);

int main(int argc, const char *argv[])
{
    char name[5][10];
    char tmp[10];
    char msg[10] = " ";
    int i;
    
    for (i = 0; i < 5; i++, strcpy(msg, " ")) 
    {
        do 
        {
            printf("Please input a name %d%s:", i, msg);
            fgets(tmp, 10, stdin);
            strcpy(msg, " again");
        } while (my_strcmp(tmp, name, i) == 0);

        strcpy(name[i], tmp);
        
    }

    for (i = 0; i < 5; i++) 
    {
        printf("%d\t%s", i, name[i]);
    }
    
    printf("\n");
    return 0;
}

int my_strcmp(char *dest, char (*src)[10], int num)
{
    int i;

    if (num == 0) 
    {
        return 1;
    }

    for (i = 0; i < num; i++) 
    {
        if (strcmp(dest, src[i]) == 0) 
        {
            return 0;
        }
    }

    return 1;
}
