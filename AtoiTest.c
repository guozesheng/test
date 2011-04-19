#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char a[10] = "";
    int i;
    long int j;
    printf("Input the number:\n");
    scanf("%s", a);
    getchar();
    printf("Input the number system:\n");
    scanf("%d", &i);
    j = strtol(a, NULL, i);
    printf("%ld\n", j);

    return 0;
}
