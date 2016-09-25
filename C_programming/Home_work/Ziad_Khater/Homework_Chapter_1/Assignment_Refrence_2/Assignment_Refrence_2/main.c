#include "stdio.h"
void main()
{
    float x=10;
    float y;
    float a,b,c;
    printf("Enter the polynomial coefficients in this form a/b/c \n");
	scanf("%f/%f/%f",&a,&b,&c);
    y=(a*x*x)+(b*x)+c;
    printf("y(x)=%f",y);
}