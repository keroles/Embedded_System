#include "stdio.h"
void main(){
	float A[100][100];
	int i, j, r, c;
	printf("enter dimensions of the matrix \n");
	scanf("%d %d", &r, &c);
	printf("enter elements of the matrix \n");
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf(" %f", &A[i][j]);
		}
	}
	for(i=0; i<c; i++){
		for(j=0; j<r; j++){
			printf(" %f", A[j][i]);
		}
		printf("\n");
	}
	system("pause");
}