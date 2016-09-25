#include "stdio.h"

int factorial(int x);

void main(){
	int no;
	printf("Enter an positive integer: ");
	scanf(" %d",&no);
	printf("factorial of %d: %d\n",no,factorial(no));
	system("pause");
}
int factorial(int x){
	if(x == 1){
		return 1;
	}
	else{
		return x* factorial(x-1);
	}
}