/*
 * Delete the substring from the master string.
 */

#include <stdio.h>

int squeeze(char *str1, char *str2);

int main(int argc, const char *argv[])
{
    char s1[] = "abcdefg";
    char s2[] = "ab";

    printf("before squeeze: s1 = %s\ns2 = %s\n", s1, s2);
    squeeze(s1, s2);
    printf("after squeeze: s1 = %s\ns2 = %s\n", s1, s2);
    
    return 0;
}

int squeeze(char *str1, char *str2)
{
    int i, j, k;

    for (i = k = 0; str1[i] != '\0'; i++) 
    {
        for (j = 0; str2[j] != 0 && str2[j] != str1[i]; j++) 
        {
            ;
        }
        if (str2[j] == 0) 
        {
            str1[k++] = str1[i];
        }
    }
    
    str1[k] = '\0';

    return 0;
}
