/*
 * printf
 */

#include <stdio.h>
#define dprint( expr )  printf("<main>" #expr "=%d \n", expr)
#define paste(front, back) front##back
#define DPRINT(fmt, args...) printf(fmt, ##args);

int main(int argc, const char *argv[])
{
    int x =100, y = 2, name1 = 100;
    
    dprint(x / y);
    dprint(x + y);
    dprint(x + y + 2);
    printf("name1 = %d\n", name1);
    paste(name, 1) = 123;
    printf("name1 = %d\n", name1);
    
#if 0
    DPRINT("a = %d b = %d", 100, 200);
    
#endif

    return 0;
}
