#include "stdio.h"

void main(){
	
	float a[100],new_Element;
	int Elements,location,i;
	printf("Enter no. of Elements: ");
	scanf(" %d",&Elements);
	for(i=0;i<Elements;i++){
		a[i]=i+1;
		printf("%g",a[i]);
	}
	printf("\nEnter the Element to be inserted: ");
	scanf(" %f",&new_Element);
	printf("Enter the location: ");
	scanf(" %d",&location);
	for(i=Elements-1;i>=location-1;i--){
		a[i+1]= a[i];
	}
	a[location-1]= new_Element;
	for(i=0;i<=Elements;i++){
		printf("%g",a[i]);
	}
	printf("\n");
	system("pause");
}