#include<stdio.h>
#include<conio.h>

void main ()
{
	char op  ;
	float num1 , num2 ;
	float ans ;
	printf("Enter operator ethier + or - or * or divide : ");
	scanf("%c",&op);
	printf("Enter two operands : ");
	scanf("%f %f",&num1 ,&num2 );
	switch(op)
	{
	case '+' :
		{
			ans = num1 + num2 ;
			break;
		}
	case '-' :
		{
			ans = num1 - num2 ;
			break ;
		}
	case '*' :
		{
			ans = num1 * num2 ;
			break ;
		}
	case '/' :
		{
			ans = num1 / num2 ;
			break ;
		}
	}
	printf("%f %c %f = %f ",num1,op ,num2,ans );
	getch();
}