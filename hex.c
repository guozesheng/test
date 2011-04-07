#include <stdio.h>

void cov(int num);

int main(int argc, const char *argv[])
{
    int num;
    printf("Please input a numer:");
    scanf("%d", &num);

    cov(num);
    printf("\n");

    return 0;
}

void cov(int num)
{
    int tmp;

    if (num / 16) 
    {
        cov(num / 16);
    }
    tmp = num % 16;
    switch(tmp)
    {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d", tmp);
    }
    
}
