#include "stdio.h"

void main(){
	
	int Elements,i;
	float a[100],search;
	printf("Enter no. of Elements: ");
	scanf(" %d",&Elements);
	printf("Enter Elements of Array: ");
	for(i=0;i<Elements;i++){
		scanf(" %f",&a[i]);
	}
	printf("Enter the Element to be searched: ");
	scanf(" %f",&search);
	for(i=0;i<Elements;i++){
		if(a[i] == search){
			printf("Number Found at the location: %d\n",i+1);
			break;
		}
	}
	system("pause");
}