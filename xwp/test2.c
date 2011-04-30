#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[] = "Hello, world!";
    int i;
    str[12] = '\n';
    i = strlen(str);
    printf("%c\n", str[i]);
    printf("%s\n", str);
    return 0;
}
