#include "stdio.h"
#define R 100
#define C 100
void main(){
    
    int i,j,r,c;
    int x[R][C],xT[R][C];
    
	printf("Enter rows and columns of the matrix : ");
	scanf("%d %d",&r,&c);

    printf("Enter the elements the matrix:\n ");
	for (i=0; i<r; i++){
		for(j=0;j<c;j++){
			printf("Enter a%d%d ",i+1,j+1);
			scanf("%d",&x[i][j]);
		}
	}
	printf("\nEntered Matrix = \n");
	for (i=0; i<r; i++){
		printf("\n");
		for(j=0;j<c;j++){
			printf("%d\t ",x[i][j]);
		}
	}
	
	//calculating the transpose
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            xT[i][j] = x[j][i];
        }
        
    }
	printf("\nTransposed Matrix = \n");
	for (i=0; i<c; i++){
		printf("\n");
		for(j=0;j<r;j++){
			printf("%d\t ",xT[i][j]);
		}
	}
    printf("\n\n####################\nEND\n####################\n");
    printf("Press any key to exit");
	scanf("%d",i);
    
}