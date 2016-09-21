#include"stdio.h"
int main()
{
	float num;
	printf("plz enter yr num : ");
	scanf("%f",&num);
	if(num>0)
		printf("num is +ve\n ");
	else if(num<0)
		printf("num is -ve \n");
	else
		printf("num is = 0\n");
	system("pause");
}