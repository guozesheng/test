/*
 * funciotn pointer
 */

#include <stdio.h>
#include <stdlib.h>

typedef int (*func_t)(int, int);

func_t aa[5];
int (*f[5])(int, int);

typedef struct
{
    char ch;
    func_t f;
} node;

int add (int a, int b){return a + b;}
int sub (int a, int b){return a - b;}
int mul (int a, int b){return a * b;}
int d (int a, int b){return a / b;}

int main(int argc, const char *argv[])
{
    int i;
    int x = atoi(argv[1]);
    int y = atoi(argv[3]);

    if (argc < 4) 
    {
        printf("Please usage: %s a + b\n", argv[0]);
        return 0;
    }
    //node a[4] = {{'+', add}, {}, {}, {}, };
    //node a[4] = {{(char)*argv[2], add}, {}, {}, {}, };
    node a[4] = {{'-', add}, {}, {}, {}, };

    for (i = 0; i < 4; i++) 
    {
        if (a[i].ch == argv[2][0]) 
        {
            printf("%d %c %d = %d\n", x, a[i].ch, y, a[i].f(x, y));
        }
    }
    
    return 0;
}
