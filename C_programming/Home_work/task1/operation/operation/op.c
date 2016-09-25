#include"stdio.h"
int main()
{
	char operation;
	float num1,num2;
	double sum=0;
	printf("enter yr operation : ");
	scanf("%c",&operation);
	printf("\nenter yr two nums :\n ");
	scanf("%f %f",&num1,&num2);
	sum=num1+num2;
	printf("%f %c %f = %lf \n",num1,operation,num2,sum);
	system("pause");
}