#include <stdio.h>
#include <string.h>

int my_strcmp(const char *dest, const char *src, int num);

int main(int argc, const char *argv[])
{
    char name[5][10];
    char tmp[10];
    int i;
    
    for (i = 0; i < 5; i++) 
    {
        printf("Please input a name %d:", i);
        fgets(tmp, 10, stdin);
        
        while (my_strcmp(tmp, name[0], i) == 0) 
        {
            printf("Please input name again %d:", i);
            fgets(tmp, 10, stdin);
        }

        strcpy(name[i], tmp);
        
    }

    for (i = 0; i < 5; i++) 
    {
        printf("%d\t%s\n", i, name[i]);
    }
    
    return 0;
}

int my_strcmp(const char *dest, const char *src, int num)
{
    int i;

    if (num == 0) 
    {
        return 1;
    }

    for (i = 0; i < num; i++) 
    {
        if (strcmp(dest, src) == 0) 
        {
            return 0;
        }
        src++;
    }

    return 1;
}
