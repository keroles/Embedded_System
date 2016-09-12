#include <stdio.h>
#include "lifo.h"

void main(){

	int x[]={1,2,3,4,5};
	int i = 0;
	int temp;
	

	for (i=0;i<5;i++){
		if(!isFull()){
			push(x[i]);
		}else{
			break;
		}
	}
	
	printf("Stack = \n");
	for (i=0;i<5;i++){
		if(!isEmpty()){
			temp = pop();
			printf("%d\n",temp);
		}else{
			break;
		}
	}
	
	printf("press any key to Exit ");
	scanf("%d",&i);
}
