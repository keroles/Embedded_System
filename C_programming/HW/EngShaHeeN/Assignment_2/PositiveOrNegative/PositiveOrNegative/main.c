#include "stdio.h"

void main(){
    
    float n;
    
	printf("Enter a number : ");
    scanf("%f",&n);
	
	if (n>0){
		printf("%.2f is POSITIVE",n);
	}
	else if(n==0){
		printf("You entered zero");
	}
	else{
		printf("%.2f is NEGATIVE",n);
	}
	
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",n);
}