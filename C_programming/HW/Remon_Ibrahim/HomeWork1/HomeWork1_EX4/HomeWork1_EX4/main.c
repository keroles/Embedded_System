#include<stdio.h>
#include<conio.h>

void main ()
{
	float var1 , var2 , var3 ;
	printf("Enter two numbers: ");
	scanf("%f %f",&var1,&var2);
	var3 = var1 * var2 ;
	printf("Product: %f",var3);
	getch();
}