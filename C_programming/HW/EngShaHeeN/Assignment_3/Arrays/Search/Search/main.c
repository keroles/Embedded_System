#include "stdio.h"
#define s 100
void main(){
    
    int i=0,n,search,index=0;
    int x[s];
	printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
		x[i] = (i+1) + 10 * (i+1);
        printf("%d ",x[i]);
    }
	printf("\nEnter the element to be searched : ");
    scanf("%d",&search);

    for(i=0;i<n;i++){
		if (x[i] == search){
			index = i+1;
			break;
		}
    }
	if (index != 0){
		printf("\nNumber found at the location : %d",index);
	}
	else{
		printf("Number Not Found");
	}
	printf("\n\n####################\nEND\n####################\n");
	printf("Press any key to exit");
	scanf("%d",i);
}