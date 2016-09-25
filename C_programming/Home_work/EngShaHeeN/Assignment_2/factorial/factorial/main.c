#include "stdio.h"

void main(){
	int i,n,factorial=1;
	printf("Enter an integer : ");
	scanf("%d",&n);
	if(n<0){
		printf("Error!!! Factorial of negative number doesn't exist");
	}
	else{
		for (i=1;i<=n;i++){
		factorial *= i;
		}
		printf("Factorial = %d ",factorial);
	}
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",n);

}