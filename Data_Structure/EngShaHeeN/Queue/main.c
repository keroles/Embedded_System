#include <stdio.h>
#include <fifo.h>

void main(){
	int x[]={1,2,3,4,5};
	int i;
	int  temp;

	for(i=0;i<5;i++){
		enqueue(x[i]);
	}
	
	printf("Queue = \n");
	for(i=0;i<5;i++){
		temp = dequeue();
		printf("%d\n",temp);
	}

	printf("Press any key to Exit");
	scanf("%d",&i);

}
