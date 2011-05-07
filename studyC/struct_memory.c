#include <stdio.h>

int main(int argc, const char *argv[])
{
    struct struct_memory_tt 
    {
        short int b;
        char a[9];
        //char b;
    } str;
    struct struct_memory_t 
    {
        int i;
        char a;
    } my_str;

    printf("%d\n", sizeof(str));
    printf("%d\n", sizeof(my_str));

    return 0;
}
