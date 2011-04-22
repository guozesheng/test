/*
 * Read a floating-point number
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
    float f;
    double d;

    scanf("%f", &f);
    scanf("%lf", &d);

    printf("%f\n", f);
    printf("%lf\n", d);

    return 0;
}
