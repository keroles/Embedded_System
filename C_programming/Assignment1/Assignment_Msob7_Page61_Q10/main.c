#include <stdio.h>

int main()
{
    unsigned char a, h, m, e, d;

    printf("Enter your password: ");

    a= getch();
    printf("*");

    h= getch();
    printf("*");

    m= getch();
    printf("*");

    e= getch();
    printf("*");

    d= getch();
    printf("*");



    if( a== 'a' && h== 'h' && m== 'm' && e== 'e' && d== 'd')
        printf("\n$$$$$$ Correct password $$$$$$");
    else
        printf("\nWrong password.");

    return 0;
}
