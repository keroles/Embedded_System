#include "stdio.h"
#define r 3
#define c 3
void main(){
    
    int i,j;
    int x[r][c],xT[r][c];
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("x[%d][%d] = ",i,j);
            scanf("%d",&x[i][j]);
        }
        
    }
	
    printf("\n####################\nINPUT\n####################\n\n");
    printf("x = ");
    for(i=0;i<r;i++){
        printf("\n");
        for(j=0;j<c;j++){
            printf("%d\t  ",x[i][j]);
        }
        
    }
	
	//calculating the transpose
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            xT[i][j] = x[j][i];
        }
        
    }
    
	printf("\n####################\nOUTPUT\n####################\n\n");
    printf("x Transpose = ");
    for(i=0;i<r;i++){
        printf("\n");
        for(j=0;j<c;j++){
            printf("%d\t  ",xT[i][j]);
        }
        
    }
    printf("\n\n####################\nEND\n####################\n");
    printf("Press any key to exit");
	scanf("%d",i);
    
}