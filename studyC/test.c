#include <stdio.h>

#define N   10

void initArray(int *p, int m, int n);

int main(int argc, const char *argv[])
{
    int a[N][N] = {{2, 4, 6}};
    a[1][0] = 3;

    //printf("%d, %d, %d\n", a[0][0], a[0][1], a[0][2]);

    initArray(a[0], N, N);

    return 0;
}

void initArray(int *p, int m, int n)
{
    //int i;
    printf("%d\n", *p);
    p++;
    printf("%d\n", *p);
}
