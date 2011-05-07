#include <stdio.h>

int world_uper(char *str);

int main(int argc, const char *argv[])
{
    char str[] = "Hello, world!";

    printf("%s\n", str);

    world_uper(str);
    printf("%s\n", str);

    return 0;
}

int world_uper(char *str)
{
    for (; *str != '\0'; str++) 
    {
        if (*str > 'a' && *str < 'z') 
        {
            *str -= 32;
        }
    }
    
    return 0;
}
