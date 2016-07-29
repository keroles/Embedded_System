#include "stdio.h"

void main(){
    
    int n;
    
	printf("Enter an integer you want to check : ");
    scanf("%d",&n);
	
	if (n%2 == 0){
		printf("%d is EVEN",n);
	}
	else{
		printf("%d is ODD",n);
	}
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",n);
}