#include "stdio.h"

void main(){
	float no1,no2,no3;
	printf("Enter three numbers: ");
	scanf(" %f %f %f",&no1,&no2,&no3);
	printf("Largest number: ",(no1>no2)? ((no1>no3)? no1:no3):((no2>no3)? no2:no3))
	system("pause");

}