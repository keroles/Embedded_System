#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x, y;
    char opr ;

    printf("Enter enter operator + or - or * or /: ");
    scanf("%c", &opr);
    printf("Enter two operands: ");
    scanf("%f %f", &x, &y);

    switch( opr )
    {
        case '+': printf("%lg + %lg = %lg.", x, y, x+y); break;

        case '-': printf("%lg - %lg = %lg.", x, y, x-y); break;

        case '*': printf("%lg * %lg = %lg.", x, y, x*y); break;

        case '/': printf("%lg / %lg = %lg.", x, y, x/y); break;

        default: printf("False operator.");            break;
    }
    return 0;
}
