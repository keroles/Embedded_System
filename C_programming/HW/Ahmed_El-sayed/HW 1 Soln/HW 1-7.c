#include "stdio.h"

void main(){
	float a,b,temp;
	printf("Enter value of a: ");
	scanf(" %f",&a);
	printf("Enter value of b: ");
	scanf(" %f",&b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("After swapping, value of a = %g\n",a);
	printf("After swapping, value of b = %g\n",b);
	system("pause");
	
}