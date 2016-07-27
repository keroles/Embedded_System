#include"stdio.h"
int main()
{
	int fact=1;
	int i;
	int num;
	printf("enter yr num :");
	scanf("%d",&num);
	if(num>=0){
	for(i=1;i<=num;i++)
		fact*=i;
	printf("fact= %d\n",fact);
	}
	else
		printf("the fact not exist\n");
	system("pause");
}