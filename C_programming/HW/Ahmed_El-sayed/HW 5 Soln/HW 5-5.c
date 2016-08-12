#include "stdio.h"

#define Area(r) (22.0/7)*r*r

void main(){

	float Radius;

	printf("Enter the radius: ");
	scanf(" %f",&Radius);
	printf("Area: %g\n",Area(Radius));
	system("pause");
	
}