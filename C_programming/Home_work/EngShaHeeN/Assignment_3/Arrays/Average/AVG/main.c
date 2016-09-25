#include "stdio.h"
#define s 100
void main(){
    
    int i=0;
	float n,sum=0,avg;
    float x[s];
    printf("Enter the number of data = ");
        scanf("%f",&n);
    for(i=0;i<n;i++){
        printf("Please, Enter the %d th number = ",i+1);
        scanf("%f",&x[i]);
    }
    for(i=0;i<n;i++){
       sum += x[i];
    }
	avg = sum / n;
	printf("\nsum = %.2f",sum);
	printf("\nAverage = %.2f",avg);
	printf("\n\n####################\nEND\n####################\n");
	printf("Press any key to exit");
	scanf("%d",i);
}