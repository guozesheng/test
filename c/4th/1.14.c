/*
 * the pointer to pointer
 */

#include <stdio.h>
#include <string.h>

int *pint;
int a;
char str[10];
char *pstr = "abcdabcdabcd";

int test_init(void);
int test_str(void);

int main(int argc, const char *argv[])
{
    test_init();
    test_str();
    
    return 0;
}

int test_str(void)
{
    printf("<test_str> 1\n");
    pstr = "bbbb";
    printf("%s\n", pstr);
    printf("<test_str> 2\n");
    strcpy(str, "ABCD");
    printf("<test_str> 3\n");
    pstr = str;
    printf("<test_str> 4\n");
    strcpy(pstr, "AB");
    printf("<test_str> 5\n");
    
    return 0;
}

int test_init(void)
{
    printf("<test_int> 1\n");
    pint = &a;
    printf("<test_int> 2\n");
    *pint = 0x12;
    printf("<test_int> 3 %d\n", *pint);
    printf("<test_int> 4 *pint = %d\n", *pint);
    printf("<test_int> 5 pint = 0x%x\n", (unsigned int)pint);
    
    return 0;
}
