#include "stdio.h"

void main(){
	
	float a[100][100],Trans[100][100];
	int i,j,Rows,columns;
	printf("Enter Size of Matrix: \n");
	printf("Enter No. Of Rows: ");
	scanf(" %d",&Rows);
	printf("Enter No. Of Columns: ");
	scanf(" %d",&columns);
	printf("\nEnter Elements of matrix: \n");
	for(i=0;i<Rows;i++){
		for(j=0;j<columns;j++){
			printf("Enter ELement a%d%d: ",i+1,j+1);
			scanf(" %f",&a[i][j]);
		}
		printf("\n");
	}
	printf("\nTranspose of Matrix: \n");
	for(i=0;i<Rows;i++){
		for(j=0;j<columns;j++){
			Trans[i][j] = a[j][i];
			printf("%g\t",Trans[i][j]);
		}
		printf("\n");
	}
	system("pause");
	
}