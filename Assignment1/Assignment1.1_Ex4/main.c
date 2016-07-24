#include <stdio.h>
#include <stdlib.h>

int main()
{

    float x, y;
    double z;

    printf("Enter two numbers: ");
    scanf("%f  %f", &x, &y);

    z= x*y ;

    printf("Product: %lf", z);
    return 0;
}
