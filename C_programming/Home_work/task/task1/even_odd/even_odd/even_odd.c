#include"stdio.h"
int main()
{
	int num;
	printf("enter the integer number :");
	scanf("%d",&num);
	printf("%d",num);
	if(num%2==0)
		
		printf(" is even\n");
	else
		printf(" is odd\n");
	system("pause");
}
