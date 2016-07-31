#include "stdio.h"
#include "conio.h"
void main()
{
	double x,y,result;
	char c;
	while(1)
	{
	printf("Please insert x then y \n");
	scanf("%lf %lf",&x,&y);
	printf("insert an operation + - / *\n");
	c=getch();

	if(c== '+')
	{
		result=x+y;
		goto printing ;
	}
	else if (c== '-')
	{
		result=x-y;
		goto printing ;
	}
	else if (c== '/') 
	{
		result=x/y;
		goto printing ;
	}	
	else if (c== '*') 
	{
		result=x*y;
		goto printing ;
	}
	else 
	{
		printf("Invalid operator\n");
		continue;
	}

	printing: printf("%lf %c %lf = %lf \n",x,c,y,result);

	}
}