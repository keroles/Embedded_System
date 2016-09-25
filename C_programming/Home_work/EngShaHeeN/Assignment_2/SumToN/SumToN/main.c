#include "stdio.h"

void main(){
	unsigned int i,n,sum=0;
	printf("Enter an integer : ");
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		sum += i;
	}
	printf("Sum = %d ",sum);
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",n);

}