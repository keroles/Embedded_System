#include "stdio.h"
void main(){
float x;
printf("enter number you want to check\n");
scanf("%f",&x);
if(x>0){
	printf("the number is positive\n");
}
else if(x<0){
	printf("the number is negative\n");
}
else{
	printf("the number is zero\n");
}
system("pause");
}