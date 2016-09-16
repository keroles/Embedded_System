#include "stdio.h"

void main(){
	
	float a[100],Average=0;
	int i,no_of_data;
	
	printf("Enter the numbers of data: ");
	scanf(" %d",&no_of_data);
	
	for(i=0;i<no_of_data;i++){
		printf("Enter Data number %d: ",i+1);
		scanf(" %f",&a[i]);
		Average += a[i];
	}
	Average /= no_of_data;
	printf("Average= %g\n",Average);
	system("pause");
	
}