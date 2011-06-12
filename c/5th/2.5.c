/*
 * my_strcmp()
 */

#include <stdio.h>

int my_strcmp(char *str1, char *str2);

int main(int argc, const char *argv[])
{
    char str1[] = "abcd";
    char str2[] = "abce";

    printf("%d\n", my_strcmp(str1, str2));
    
    return 0;
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] == str2[i]) 
    {
        if (str1[i] == '\0') 
        {
            return 0;
        }
        i++;
    }
    
    if (str1[i] < str2[i]) 
    {
        return -1;
    }
    else 
    {
        return 1;
    }

    return 0;
}
