#include "stdio.h"

void main(){
	float no;
	printf("Enter a number: ");
	scanf("%f",&no);
	if(no>0){
		printf("%g is positive.\n",no);
	}
	else if(no<0){
		printf("%g is negative.\n",no);
	}
	else{
		printf("You Entered Zero.\n");
	}
	system("pause");

}