#include "stdio.h"

#define r 3
#define c 3
int main(){
	
	int i,j,temp;
	int x[r][c],y[r][c],z[r][c];
	printf("Enter the elements of 1st matrix:\n ");
	for (i=0; i<r; i++){
		for(j=0;j<c;j++){
			printf("Enter a%d%d ",i+1,j+1);
			scanf("%d",&x[i][j]);
		}
	}
	printf("A = \n");
	for (i=0; i<r; i++){
		printf("\n");
		for(j=0;j<c;j++){
			printf("%d\t ",x[i][j]);
		}
	}
	printf("\nEnter the elements of 2nd matrix:\n ");
	for (i=0; i<r; i++){
		for(j=0;j<c;j++){
			printf("Enter b%d%d ",i+1,j+1);
			scanf("%d",&y[i][j]);
		}
	}
	printf("\nB = \n");
	for (i=0; i<r; i++){
		printf("\n");
		for(j=0;j<c;j++){
			printf("%d\t ",y[i][j]);
		}
	}
	for (i=0; i<r; i++){
		for(j=0;j<c;j++){
			z[i][j] = x[i][j] + y[i][j];
		}
	}
	printf("\nSum of Matrix : \n");
	for (i=0; i<r; i++){
		printf("\n");
		for(j=0;j<c;j++){
			printf("%d\t ",z[i][j]);
		}
	}

	printf("\n\n####################\nEND\n####################\n");
    printf("Press any key to exit");
	scanf("%d",i);
	return 0;
}