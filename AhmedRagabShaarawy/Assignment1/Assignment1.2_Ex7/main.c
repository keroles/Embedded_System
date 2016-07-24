#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    unsigned long product= 1;
    printf("Enter an integer: ");
    scanf("%d", &n);
    if( n> 0)
    {
        while( n!= 1)
        {
            product *= n;
            n--;
        }
        printf("Factorial = %li.\n", product);
    }
    else if( n< 0 )
        printf("Errpr!!factorial of negative number does not exist.\n");

    else
        printf("Factorial = 1.");

    return 0;
}
