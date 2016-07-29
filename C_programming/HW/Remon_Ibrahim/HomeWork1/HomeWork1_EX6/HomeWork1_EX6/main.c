#include<stdio.h>
#include<conio.h>

void main ()
{
	float a , b , t ;
	printf("Enter value of a: ");
	scanf("%f",&a);
	printf("Enter value of b: ");
	scanf("%f",&b);
	t = a ;
	a = b ;
	b = t ;
	printf("\r\nAfter swapping, value of a = %.2f",a);
	printf("\r\nAfter swapping, value of b = %.2f",b);



	getch();
}