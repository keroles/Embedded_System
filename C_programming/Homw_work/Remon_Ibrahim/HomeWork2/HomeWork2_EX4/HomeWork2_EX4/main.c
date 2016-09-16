#include<stdio.h>
#include<conio.h>

void main()
{
	float num ;
	printf("Enter a number : ");
	scanf("%f",&num);
	if ( num > 0 )
	{
		printf("%f is positive.",num);
	}
	else if ( num < 0 )
	{
		printf("%f is negative.",num);
	}
	else
	{
		printf("You enterd zero.");
	}
	getch();
}
