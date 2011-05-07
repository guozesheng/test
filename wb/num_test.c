#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int init_array(int *a, int len);
int print_array(int *a, int len);
int sort_array(int *a, int len);
int sort_array_pointer(int *a, int len);

int main(int argc, const char *argv[])
{
    int a[8];
    int len = 8;

    init_array(a, len);
    print_array(a, len);

    sort_array_pointer(a, len);
    print_array(a, len);
    
    return 0;
}

int sort_array_pointer(int *a, int len)
{
    int *p = a;
    int *q = a + len - 1;
    int temp;

    while (p < q) 
    {
        while ((*p % 2) && (p < q)) 
        {
            p++;
        }
        while (!(*q % 2) && (p < q)) 
        {
            q--;
        }

        temp = *p;
        *p = *q;
        *q = temp;
    }
    
    return 0;
}

int sort_array(int *a, int len)
{
    int start = 0;
    int end = len;
    int temp;

    while (start < end) 
    {
        while ((*(a + start) % 2 == 1) && (start < end)) 
        {
            start++;
        }
        while ((*(a + end) % 2 == 0) && (start < end)) 
        {
            end--;
        }

        temp = *(a + start);
        *(a + start) = *(a + end);
        *(a + end) = temp;
    }
    
    return 0;
}

int print_array(int *a, int len)
{
    int i;

    for (i = 0; i < len; i++) 
    {
        printf("%4d", *(a + i));
    }
    
    printf("\n");
    return 0;
}

int init_array(int *a, int len)
{
    int i;

    srand(time(NULL));
    for (i = 0; i < len; i++) 
    {
        *(a + i) = rand() % 80 + 20;
    }
    
    return 0;
}
