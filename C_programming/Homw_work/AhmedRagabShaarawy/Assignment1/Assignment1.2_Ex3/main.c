#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x, y, z;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Largest number = %lf", x>y ? x> z ? x : z : y>z ? y : z );

    return 0;
}
