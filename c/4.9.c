/*
 * 调整数组中数字的顺序，使奇数在前
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i, j, tmp;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 88};
    int len = sizeof(a) / sizeof(int);

    printf("before modified:\n");

    for (i = 0; i < len; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0, j = len - 1; i < j; i++) 
    {
        if (a[i] % 2 == 0) 
        {
            while (a[j] % 2 == 0) 
            {
                j--;
            }
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            j--;
        }
    }

    printf("after modified:\n");
    for (i = 0; i < len; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    printf("sizeof(a) = %d, len = %d\n", sizeof(a), len);
    printf("\n");
    return 0;
}
