#include "stdio.h"

void main(){
	
	int lower,upper,i,j,flag=0,flag1=0;
	printf("Enter two numbers(intervals): ");
	scanf("%d %d",&lower,&upper);
	printf("Prime numbers between %d and %d: ",lower,upper);
	for(i=(lower<2)? 2:lower;i<upper;i++){
		for(j=2;j<i;j++){
			if(i%j == 0){
				flag1 = 1;
				break;
			}	
		}
		if(flag1 == 0){
			flag = 1;
			printf("%d  ",j);
		}
		flag1 = 0;
	}
	if(flag == 0){
		printf("Nothing\n");
	}
	printf("\n");
	system("pause");
}