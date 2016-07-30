#include "stdio.h"
#define s 7
void main(){
    
    int i=0,max=0,min,MaxInd,MinInd;
    int x[s];
    
    for(i=0;i<s;i++){
        printf("Please, Enter the %d th element of the Array = ",i);
        scanf("%d",&x[i]);
    }
    min=x[1];
    for(i=0;i<s;i++){
        if (x[i] > max){
            max = x[i];
            MaxInd = i;
        }
        if (x[i] < min){
            min = x[i];
            MinInd = i;
        }
    }
	printf("\n####################\nOUTPUT\n####################\n\n");
    printf("Maximun element = %d and its INDEX = %d\n",max,MaxInd);
    printf("Minimum element = %d and its INDEX = %d",min,MinInd);
    
	printf("\n\n####################\nEND\n####################\n");
	printf("Press any key to exit");
	scanf("%d",i);
    
}