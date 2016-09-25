#include <stdio.h>
#include<conio.h>

void main()
{
	int num ;
	printf("Enter an intger you want to check : ");
	scanf("%d",&num);
	if ( num & 1 )
	{
		printf("%d is odd.",num);
	}
	else 
	{
		printf("%d is even.",num);
	}
	getch();
}