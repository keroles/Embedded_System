#include "stdio.h"
void main(){
	float A[2][2], B[2][2], sum[2][2];
	int i, j;
	printf("enter elements of the first 2*2 matrix \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			scanf("%f", &A[i][j]);
		}
	}
	printf("enter elements of the second 2*2 matrix \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			scanf("%f", &B[i][j]);
		}
	}
for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			sum[i][j] = A[i][j] + B[i][j];
			printf(" %f", sum[i][j]);
		}
		printf("\n");
}
system("pause");
}