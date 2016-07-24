#include <stdio.h>
#include <stdlib.h>

int main()
{

    unsigned long result= 0;
    unsigned int n;
    printf("Enter an integer: ");
    scanf("%i", &n);

    while( n )
    {
        result+= n;
        n--;
    }
    printf("Sum = %d", result);
    return 0;

}
