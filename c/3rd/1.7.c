/*
 * Check the duplication number from integer
 */

#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int Bool;

int main(int argc, const char *argv[])
{
    Bool digit_seen[10] = {0};
    int digit;
    long n;

    printf("Enter a number:");
    scanf("%ld", &n);
    while (n > 0) 
    {
        digit = n % 10;
        if (digit_seen[digit]) 
        {
            break;
        }
        digit_seen[digit] = TRUE;
        n /= 10;
    }
    if (n > 0) 
    {
        printf("Repeated digit\n");
    }
    else 
    {
        printf("No repeated digit\n");
    }

    return 0;
}
