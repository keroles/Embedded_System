#include "stdio.h"

void main(){
	char c;
	float operand1,operand2,resault;
	printf("Enter an operator ('+','-','*','/'): ");
	scanf("%c",&c);
	printf("Enter First operand : ");
	scanf("%f",&operand1);
	printf("Enter second operand : ");
	scanf("%f",&operand2);
	switch(c){
		case '+':
		{
			resault = operand1 + operand2;
			printf("%.2f %c %.2f = %.2f",operand1,c,operand2,resault);
		}
			break;
		case '-':
		{
			resault = operand1 - operand2;
			printf("%.2f %c %.2f = %.2f",operand1,c,operand2,resault);
		}
			break;
		case '*':
		{
			resault = operand1 * operand2;
			printf("%.2f %c %.2f = %.2f",operand1,c,operand2,resault);
		}
			break;
		case '/':
		{
			if(operand2 == 0){
				printf("Error! \nCan't divide by zero");
			}
			else{
				resault = operand1 / operand2;
				printf("%.2f %c %.2f = %.2f",operand1,c,operand2,resault);
			}
		}
			break;
		default:
			{
				printf("Error! \nInvalid operator");
			}
	}
	
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",c);

}