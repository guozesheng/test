/*
 * 将1--200间不能被3整除的数输出
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i;

    for (i = 0; i <= 200; i++) 
    {
        if (i % 3 != 0) 
        {
            printf("%d\t", i);
        }
    }

    printf("\n");
    return 0;
}
