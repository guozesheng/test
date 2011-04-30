#include <stdio.h>

int com_bit(unsigned int n);
int sort(unsigned int *a, int len);
void swap(unsigned int *a, unsigned int *b);

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

void swap(unsigned int *a, unsigned int *b)
{
    unsigned int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int sort(unsigned int *a, int len)
{
    int i, j;
    int b1, b2;

    for (i = 0; i < len - 1; i++) 
    {
        b1 = com_bit(*(a + i));
        for (j = i + 1; j < len; j++) 
        {
            b2 = com_bit(*(a + j));
            if (b1 > b2) 
            {
                swap(a + i, a + j);
            }
            else if (b1 == b2) 
            {
                if (*(a + i) > *(a + j)) 
                {
                    swap(a + i, a + j);
                }
            }
        }
    }

    
    return 0;
}

int com_bit(unsigned int n)
{
    int num = 0;
    int mask = 0x01;
    int i;

    for (i = 0; i < sizeof(int) * 8; i++, mask <<= 1) 
    {
        num += (n & mask) != 0 ? 1 : 0;
    }
    
    return num;
}
