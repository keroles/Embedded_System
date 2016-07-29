#include "stdio.h"

void main(){
	unsigned int no,i,sum=0;
	printf("Enter an integer: ");
	scanf(" %d",&no);
	for(i=1;i<=no;i++){
		sum += i;
	}
	printf("Sum = %d\n",sum);
	system("pause");

}