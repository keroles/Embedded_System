#include "stdio.h"

void main(){
	
	int i,j;
	float a[2][2],b[2][2],sum[2][2];
	printf("Enter Elements of 1st Matrix: \n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter a%d%d: ",i+1,j+1);
			scanf(" %f",&a[i][j]);
		}
		printf("\n");
	}
	printf("Enter Elements of 2nd Matrix: \n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter b%d%d: ",i+1,j+1);
			scanf(" %f",&b[i][j]);
			sum[i][j] = a[i][j] + b[i][j];
		}
		printf("\n");
	}
	printf("\nSum of Matrix: \n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%.1f\t",sum[i][j]);
		}
		printf("\n");
	}
	system("pause");
}