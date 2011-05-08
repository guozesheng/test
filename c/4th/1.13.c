/*
 * the pointer to pointer 1
 * demo helloworld application
 */

#include <stdio.h>

int a = 0x00313233;
void *p = (void *)0;

struct t 
{
    char a;
    char b;
    short c;
} ;

int main(int argc, const char *argv[])
{
    p = (void *)&a;

    printf("char value = %c\n", *(char *)p);
    printf("int value = 0x%x\n", *(int *)p);
    printf("float value = %f\n", *(float *)p);
    printf("string value = %s\n", (char *)p);

    printf("struct.a = %c\n", ((struct t *)p)->a);
    printf("struct.b = %c\n", ((struct t *)p)->b);
    printf("struct.c = %d\n", ((struct t *)p)->c);

    ((struct t *)p)->c = 0x30;

    printf("a = 0x%x\n", a);
    printf("string value = %s\n", (char *)p);
    printf("pointer address = 0x%x\n", (unsigned int)p);
    
    return 0;
}
