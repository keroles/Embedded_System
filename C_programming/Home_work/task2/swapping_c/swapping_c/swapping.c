#include"stdio.h"
int main()
{
	float num1,num2;
	float sub=0;
	printf("enter two nums before swapping : \n");
	scanf("%f%f",&num1,&num2);
	sub=num1-num2;
	num2+=sub;
	num1-=sub;
	printf("enter two nums after swapping \n%f \n%f \n",num1,num2);
	system("pause");
}