#include <stdio.h>

int com_bit(int n);
int sort(unsigned int *a, int len);

int main(int argc, const char *argv[])
{
    unsigned int a[5] = {1, 2, 3, 4, 5};
    int i;

    sort(a, 5);

    for (i = 0; i < 5; i++) 
    {
        printf("%4d", a[i]);
    }
    
    printf("\n");
    return 0;
}

int sort(unsigned int *a, int len)
{
    int i, j;
    int temp;
    int b1, b2;

    for (i = 0; i < len - 1; i++) 
    {
        for (j = i + 1; j < len; j++) 
        {
            b1 = com_bit(*(a + i));
            b2 = com_bit(*(a + j));
            printf("%d%%%d:%d, %d%%%d:%d\n", *(a + i), i, b1, *(a + j), j, b2);
            if (b1 > b2) 
            {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
            else if (b1 == b2) 
            {
                if (*(a + i) > *(a + j)) 
                {
                    temp = *(a + i);
                    *(a + i) = *(a + j);
                    *(a + j) = temp;
                }
            }
        }
    }

    
    return 0;
}

int com_bit(int n)
{
    int num = 0;
    int mask = 0x01;
    int i;

    for (i = 0; i < 32; i++, mask <<= 1) 
    {
        num += (n & mask) != 0 ? 1 : 0;
    }
    
    return num;
}
