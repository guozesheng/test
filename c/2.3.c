/*
浮点数打印
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    double d1 = 12.0, d2 = 12.0;
    printf("%f\n", 1.0E20);
    printf("%f\n", (1.0E20 - 1.0E20) + 3.14);
    printf("%f\n", 1.0E20 + 3.14);
    printf("%f\n", 1.0E20 - (1.0E20 + 3.14));
    if (d1 == d2)
        printf("d1 = d2\n");
    return 0;
}

/*
1.0E20 = 100000000000000000000.000000;
1.0E20 + 3.14 -->%f-->100000000000000000000.000000;
*/
