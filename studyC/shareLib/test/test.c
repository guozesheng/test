#include <stdlib.h>
#include <time.h>
int test_print(void)
{
    int n;
    
    srand(time(NULL));

    n = rand() % 100;
    
    return n;
}
