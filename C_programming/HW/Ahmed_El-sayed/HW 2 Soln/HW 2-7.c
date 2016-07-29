#include "stdio.h"

void main(){
	int no,i,Factorial = 1;
	printf("Enter an integer: ");
	scanf(" %d",&no);
	if(no < 0){
		printf("Error!!! Factorial of negative number doesn't exist.\n");
	}
	else if(no == 0){
		printf("Factorial = 1\n");
	}
	else{
		for(i=no;i>1;i--){
			Factorial *= i;
		}
		printf("Factorial = %d\n",Factorial);
	}
	system("Pause");
}