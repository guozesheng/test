#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i;
    int j = 0;
    int a[32];

    printf("Plese input a numer: ");
    scanf("%d", &i);

    while (i) 
    {
        a[j++] = i % 2;
        i = i / 2;
    }
    while (j--) 
    {
        printf("%d", a[j]);
    }
    printf("\n");
    return 0;
}
