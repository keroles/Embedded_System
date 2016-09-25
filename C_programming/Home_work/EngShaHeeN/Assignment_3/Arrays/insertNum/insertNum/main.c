#include "stdio.h"
#define s 100
void main(){
    
    int i=0,n,insert,index;
    int x[s],y[s];
	printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
		x[i] = i+1;
        printf("%d ",x[i]);
    }
	printf("\nEnter the element to be inserted : ");
    scanf("%d",&insert);
	printf("\nEnter the location : ");
    scanf("%d",&index);

    for(i=0;i<n+1;i++){
		if (i > index-1){
			y[i] = x[i-1];
		}
		else if(i == index-1){
			y[i] = insert;
		}
		else{
			y[i] = x[i];
		}
    }
	for(i=0;i<n+1;i++){
        printf("%d ",y[i]);
    }
	printf("\n\n####################\nEND\n####################\n");
	printf("Press any key to exit");
	scanf("%d",i);
}