#include "stdio.h"
void main(){
	int x;
	printf("enter number you want to check \n");
	scanf("%d", &x);
	if(x%2==0){
		printf("%d is even number\n", x);
	}
	else{
		printf("%d is odd number\n", x);
	}
	system("pause");
}