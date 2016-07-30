#include "stdio.h"

#define s 3

int main(){
	
	int i,temp;
	int x[s],y[s];

	for (i=0; i<s; i++){
		printf("Enter the %d th element of x: ",i);
		scanf("%d",&x[i]);
	}
	for (i=0; i<s; i++){
		printf("Enter the %d th element of y: ",i);
		scanf("%d",&y[i]);
	}
	for(i=0; i<s; i++){
		/*
		temp =x[i];
		x[i]=y[i];
		y[i]=temp ;
		*/
		/*
		x[i] += y[i];
		y[i] = x[i] - y[i];
		x[i] = x[i] - y[i];
		*/
		y[i]=y[i]<<8;
		x[i]=x[i]||y[i];
		y[i]=x[i] & 0x00ff;
		x[i]=x[i]>>8;
	}
	printf("x\ty\n");
	for (i=0;i<s;i++){
		printf("%d\t%d\n",x[i],y[i]);
	}


	scanf("%d",&i);

}