#include "stdio.h"

void main(){
	unsigned char operation=255;
	float no1,no2;
	double result;
	while(operation != '+' && operation != '-' && operation != '*' && operation != '/' ){
		printf("Enter operator either + or - or * or /: ");
		scanf(" %c",&operation);
		printf("\n");
	}
	printf("Enter Two Operands: ");
	scanf(" %f %f",&no1,&no2);
	switch(operation){
		case '+': 
					result = no1 + no2;
					break;
		case '-':
					result = no1 - no2;
					break;
		case '*':
					result = no1 * no2;
					break;
		case '/':
					result = no1 / no2;
					break;
	}
	printf("%g %c %g = %lg\n",no1,operation,no2,result);
	system("Pause");
}