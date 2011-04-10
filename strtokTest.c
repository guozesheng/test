#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char str[] = "ihiaakksisaisaasssssssssss:";
    char *p = str;
    p = strtok(p, "i");
    printf("%s\n", p);
    p = strtok(NULL, "a");
    printf("%s\n", p);

    return 0;
}
