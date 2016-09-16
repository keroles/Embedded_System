#include <stdio.h>
#include <conio.h>

void main ()
{
	int num , i = 1 ;
	long long fact = 1 ;
	printf("Enter an intger : ");
	scanf("%d",&num);
	if ( num == 0 )
	{
		fact = 1 ;
		printf("Factorial =  : %d",fact);
	}
	else if ( num > 0 ) 
	{
		for ( i ; i<= num ; i++ )
		{
			fact *= i ;
		}
		printf("Factorial =  : %d",fact);
	}
	else 
	{
		printf("Error!!! Factorial of negative numbers doesnot exist.");
	}
	getch();
}
