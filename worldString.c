#include <stdio.h>

int main(int argc, const char *argv[])
{
    char s[] = "Hello! My C world!";
    int a[20] = {0};
    int i, j;
    char *p = s;
    printf("%s\n", s);

    for (i = 0, j = 1; i < sizeof(s); i++) 
    {
        if (s[i] == ' ') 
        {
            a[j++] = i + 1;
            s[i] = '\0';
        }
    }

    for (i = 0; i < j; i++) 
    {
        printf("%s\n", p+a[i]);
    }

    return 0;
}
