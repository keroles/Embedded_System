#include "stdio.h"
void main(){
	float x, y, z;
	printf("enter three numbers to find the greatest \n");
	scanf("%f %f %f", &x, &y, &z);
	if(x>y && x>z){
		printf("number %f is the greatest \n", x);}
	else if(y>x && y>z){
		printf("number %f is the greatest \n", y);}
	else if(z>x && z>y){
		printf("number %f is the greatest \n", z);}
	else {
		printf("couldn't find the greatest\n");
	}
	system("pause");
}