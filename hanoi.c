#include <stdio.h>

void hanoi(char a, char b, char c, int n);

int i = 1;

int main(int argc, const char *argv[])
{
    int n;
    printf("Please input the nubmer:\n");
    scanf("%d", &n);

    hanoi('A', 'B', 'C', n);
    
    return 0;
}

void hanoi(char a, char b, char c, int n)
{
    if (n == 1) 
    {
        printf("%d:%c------>%c\n", i++, a, c);
        return ;
    }
    hanoi(a, c, b, n-1);
    printf("%d:%c------>%c\n", i++, a, c);
    hanoi(b, a, c, n-1);
}
