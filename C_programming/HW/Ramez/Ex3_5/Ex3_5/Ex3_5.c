#include "stdio.h"
void main(){
	int A[100], i, n, e;
	printf("enter number of elements of the vector \n");
	scanf(" %d", &n);
	printf("enter elements of the vector \n");
	for(i=0; i<n; i++){
		scanf(" %d", &A[i]);
	}
printf("enter element you want to find \n");
scanf(" %d", &e);
for(i=0; i<n; i++){
	if(e == A[i]){
		printf("location: %d \n", i+1);
	}
}
system("pause");
}