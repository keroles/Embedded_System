#include <stdio.h>

int main()
{
    int x, y;
    long z;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    z= (long) (x+y);

    printf("Sum: %d", z );

    return 0;
}
