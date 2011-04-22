/*
 * 统计某字符串中某指定字符出现的次数
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int sum = 0;
    char a[20] = "Hello, world!";
    char c = 'o';

    while (a[i] != '\0') 
    {
        if (a[i++] == c) 
        {
            sum++;
        }
    }

    printf("%d '%c' in \"%s\"\n", sum, c, a);
    return 0;
}
