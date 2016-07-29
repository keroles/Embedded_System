#include "stdio.h"

void main(){
    
    float n1,n2,n3,largest=0;
    
	printf("Enter the first number : ");
    scanf("%f",&n1);
	printf("Enter the second number : ");
    scanf("%f",&n2);
	printf("Enter the third number : ");
    scanf("%f",&n3);
	
	if (n1>n2){
		largest = n1;
	}
	else{
		largest = n2;
	}
	if(n3>largest){
		largest = n3;
	}
	printf("Largest number = %.2f",largest);
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",n1);
}