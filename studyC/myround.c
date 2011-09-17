#include <stdio.h>
#include <math.h>

float myround(float x);

int main(int argc, const char *argv[])
{
    float d;

    printf("Input the float number:");
    scanf("%f", &d);
    printf("%f\n", myround(d));
    
    return 0;
}

float myround(float x)
{
    float dtemp;

    if (x > 0)
    {
        dtemp = ((x - floor(x)) > 0.4) ? ceil(x) : floor(x) ;
    }
    else 
    {
        dtemp = ((x - ceil(x)) < -0.4) ? floor(x) : ceil(x) ;
    }
    
    return dtemp;
}
