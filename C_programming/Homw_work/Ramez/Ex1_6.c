#include "stdio.h"

void main(){
	float x, y, temp;
	printf("enter two numbers a and b you want to swap \n");
	scanf("%f %f", &x, &y);
	temp = x;
	x = y;
	y = temp;
	printf("after swapping, the value of a = %f \n after swapping the value of b = %f \n", x, y);
	system("pause");
}