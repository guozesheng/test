/*
 * Basics of pointer
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a = 'A', b = 'X';
    char *p = NULL;
    printf("addr a = 0x%x, a = %c\n", &a, a);
    printf("addr b = 0x%x, b = %c\n", &b, b);

    p = &a;
    *p = 'Y';
    printf("p(a) = 0x%x, *p = %c\n", p, *p);
    
    p = &b;
    *p = 'B';
    printf("p(b) = 0x%x, *p = %c\n", p, *p);

    return 0;
}

/*
 * warning: format ‘%x’ expects type ‘unsigned int’, but argument 2 has type
 * ‘char *’ at 11, 12, 16, 20.
 */
