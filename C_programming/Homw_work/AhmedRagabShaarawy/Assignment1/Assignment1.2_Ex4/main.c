#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x;

    printf("Enter a number: ");
    scanf("%lf", &x);
    if( x> 0 )
        printf("%lf is positive.", x);

    else if( x< 0 )
        printf("%lf is negative.", x);

    else
        printf("You entered zero.");

    return 0;
}
