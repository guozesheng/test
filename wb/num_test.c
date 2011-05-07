#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int init_array(int *a, int len);
int print_array(int *a, int len);
int sort_array(int *a, int len);
int sort_array_pointer(int *a, int len);
int sort_array_insert(int *a, int len);

int main(int argc, const char *argv[])
{
    int a[8];
    int len = 8;

    init_array(a, len);
    print_array(a, len);

    sort_array_insert(a, len);
    print_array(a, len);
    
    return 0;
}

int sort_array_insert(int *a, int len)
{
    int i;
    int start = 0;
    int end = len;
    int temp;

    for (i = 0; i < len; i++)
    {
        while (1) 
        {
            start = 0;
            end = len - 1;
            if (*(a + i) % 2) 
            {
                while ((start < i) && !(*(a + start) > *(a + i)))
                {
                    if (!(*(a + i) % 2))
                    {
                        break;
                    }
                    start++;
                }
                if (i == start)
                {
                    break;
                }
                temp = *(a + i);
                *(a + i) = *(a + start);
                *(a + start) = temp;
            }
            else 
            {
                while ((i < end) && !(*(a + i) < *(a + end)))
                {
                    if (*(a + end) % 2)
                    {
                        break;
                    }
                    end--;
                }
                temp = *(a + i);
                *(a + i) = *(a + end);
                *(a + end) = temp;
            }
            if (i == end || i == start) 
            {
                break;
            }
        }
    }
    
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
    int i, j;

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

    for (i = 0; i < start - 1; i++) 
    {
        for (j = i + 1; j < start; j++) 
        {
            if (*(a + i) > *(a + j)) 
            {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
    for (i = end; i < len - 1; i++) 
    {
        for (j = i + 1; j < len; j++) 
        {
            if (*(a + i) > *(a + j)) 
            {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
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
        *(a + i) = rand() % 90 + 10;
    }
    
    return 0;
}
