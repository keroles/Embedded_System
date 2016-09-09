
#include<stack.h>


int main(void)
{
	char check= 1;
	int data= 5;
	int data1= 0 ;
	
	check= push( data );
	printf("check= %d\n", check);
	check= pull( &data1 );
	printf("check= %d\n", check);
	printf("data= %d\n", data1);
	
	return 0;
}
