#include "stdio.h"
void main(){
	int x, i, j, k=0;
	printf("enter an integer \n");
	scanf("%d", &x);
	j = x;
	for(i=j-1; i>0; i--){
		x = x + i;
	}
	printf("sum is %d \n", x);
	system("pause");
}