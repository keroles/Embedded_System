#include "stdio.h"
void main(){
	float A[100], e;
	int i, n, p;
	printf("enter number of elements \n");
	scanf("%d", &n);
	printf("enter elements of the vector \n");
	for(i=0; i<n; i++){
		scanf(" %f", &A[i]);
	}
	printf("enter element to be inserted \n");
	scanf(" %f", &e);
	printf("enter location \n");
	scanf(" %d", &p);
	A[p-1] = e;
	for(i=0; i<n; i++){
		printf(" %f", A[i]);
	}
	printf("\n");
	system("pause");
}