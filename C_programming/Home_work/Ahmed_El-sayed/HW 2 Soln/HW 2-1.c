#include "stdio.h"

void main(){
	int no;
	printf("Enter an integer you want to check: ");
	scanf(" %d",&no);
	if(no % 2 ==0){
		printf("%d is an even number.\n",no);
	}
	else{
		printf("%d is an odd number.\n",no);
	}
	system("pause");
	
}