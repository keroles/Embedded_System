#include "stdio.h"

int fact(int n);
void main(){
	int x,n;
	printf("Enter the number of factorial : ");
	scanf("%d",&n);

	x=fact(n);

	printf("\n%d! = %d",n,x);
	scanf("%d",&n);
}
/*
resault = 1;
while(n!=0){
	resault *=n
		n--;
}
*/

int fact(int n){
	int resault = 1;
	if(n!=0){
		resault *= n;
		n--;
		resault *= fact(n);
	}
return resault;
}