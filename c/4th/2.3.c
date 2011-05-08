/*
 * the argument of the pointer point to the pointer
 */

#include <stdio.h>
#include <string.h>

int foo(char **p);

int main(int argc, const char *argv[])
{
    char *p = NULL;

    foo(&p);
    printf("%s\n", p);
    printf("%d\n", strlen(p));

    return 0;
}

int foo(char **p)
{
    *p = "hello";
    
    return 0;
}
