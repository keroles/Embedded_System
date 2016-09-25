#include"stdio.h"
int main()
{
	float a,b,temp=0;
	printf("enter two nums : \n");
	scanf("%f%f",&a,&b);
	temp=a;
	a=b;
	b=temp;
	printf("tow nums after swapping = \n%f \n%f\n",a,b);
	system("pause");
}