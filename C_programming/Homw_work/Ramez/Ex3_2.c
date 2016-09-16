#include "stdio.h"
void main(){
	float A[100], avg = 0;
	int i, n;
	printf("enter number of elements you want to enter \n");
	scanf("%d", &n);
	printf("enter elements of the vector \n");
	for(i=0; i<n; i++){
		scanf(" %f", &A[i]);
		avg = avg + A[i];
	}
	avg = avg/n;
	printf("average of numbers is %f \n", avg);
	system("pause");
}