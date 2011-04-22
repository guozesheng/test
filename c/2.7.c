/*
字符串打印
*/

#include <stdio.h>
#include <string.h>
#define N 30

int main(int argc, char *argv[])
{
    char c = 'A';
    char a[N] = "Wang_lei@abc.com";
    int i;
    printf("c = %c\n", c);
    if ((c >= 'A') && (c <= 'Z'))
    {
        printf("A to lower %c\n", c+32);
    }
    printf("49:%c, %d\n", 49, 49);
    printf("len of char array = %d\n", sizeof(a)/sizeof(char));
    printf("strlen(a) = %d", strlen(a));
    printf("Email address:");
    for (i = 0; i < strlen(a); i++)
        printf("%c", a[i]);
    printf("\n");
    return 0;
}
