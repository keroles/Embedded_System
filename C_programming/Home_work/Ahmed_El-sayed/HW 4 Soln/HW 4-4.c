#include "stdio.h"

int power(int no,int pow);

void main(){
	int no,pow;
	printf("Enter base number: ");
	scanf(" %d",&no);
	printf("Enter power number(positive number): ");
	scanf(" %d",&pow);
	printf("%d^%d = %d\n",no,pow,power(no,pow));
	system("pause");
}
int power(int no,int pow){
	if(pow == 1){
		return no;
	}
	else{
		return no*power(no,pow-1);
	}
}