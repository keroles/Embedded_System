#include <stdio.h>
#include <conio.h>

void main ()
{
	int num , sum = 0 , i = 1 ;
	printf("Enter an intger : ");
	scanf("%d",&num);
	for ( i ; i<= num ; i++ )
	{
		sum += i ;
	}
	printf("Sum : %d",sum);
	getch();
}
