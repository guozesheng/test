#include <stdio.h>

#define LEN 10

int cale_sum(int *a);

int main(int argc, const char *argv[])
{
    //int a[LEN] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    //int a[LEN] = {-91, -41, -41, -41, -41, -41, -41, -41, -41, -41};
    int a[LEN] = {-91, -41, -41, -41, 53, -41, -41, -41, -41, -41};
    int sum_max;

    sum_max = cale_sum(a);
    printf("%d\n", sum_max);
    
    return 0;
}

int cale_sum(int *a)
{
    int sum = 0;
    int sum_max = 0;
    int start = 0;
    int end = LEN;
    int i, j;

    sum_max = *a;
    while (start <= end && *(a + start) <= 0) 
    {
        sum_max = (sum_max < *(a + start)) ? *(a + start) : sum_max;
        start++;
    }

    if (start > end)    // all the num is negative number 
    {
        return sum_max;
    }

    while (*(a + end) <= 0) 
    {
        end--;
    }

    for (i = start; i < end; i++, sum = 0) 
    {
        for (j = i; j < end; j++) 
        {
            sum += *(a + j);
            sum_max = (sum_max < sum) ? sum : sum_max;
        }
    }
    
    return sum_max;
}
