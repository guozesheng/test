#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i, a[32];
    int j = 0;

    printf("Plese input a numer: ");
    scanf("%d", &i);

    while (i) 
    {
        a[j++] = i % 2;
        i = i / 2;
    }
    if (j == 0) 
    {
        printf("0");
    }
    else 
    {
        while (j--) 
        {
            printf("%d", a[j]);
        }
    }
    printf("\n");
    return 0;
}
