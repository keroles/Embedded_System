
#include<stack.h>

int top= -1;
int stack[MAX_SIZE]={0};




char isEmpty(void)
{
	char check= 0;
	if( top== -1 )
		check= 1;
	else
		check= 0;
	return check;
}
char isFull(void)
{
	char check= 0;
	if( top== MAX_SIZE -1 )
		check= 1;
	else
		check= 0;
	return check;
}
char push( int data )
{
	char check= 0;
	check= isFull();
	if( !check)
	{
		stack[++top]= data;
		check= 1;
	}
	else
		check= 0;
	return check;
}
char pull(int *pulledData)
{
	char check= 0;
	check= isEmpty();
	if( !check)
	{
		*pulledData= stack[top];
		top-- ;
		check= 1;
	}
	else
		check= 0;
	return check;
}












