#include "stdio.h"
#define s 6

void main(){

	int x[s]={6,5,4,3,2,1},y[s];
	int i,j,temp;

	for (i=0;i<s;i++){
		for(j=i;j>0;j--){
			if(x[j]<x[j-1]){
				temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			
			}
			else{
				break;
			}
		
		}

	
	}
	for(i=0;i<s;i++){
		printf("%d\n",x[i]);
	}
	scanf("%d",&i);

}