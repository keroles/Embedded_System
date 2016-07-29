#include"stdio.h"
int main(){

int size,i;
float array[100],sum=0;
printf("Enter the size of array\n");
scanf(" %d",&size);
printf("Enter the elments you want to store\n");
for(i=0;i<size;i++){
	scanf(" %f",&array[i]);}

printf("the average of stored elements is ");
for(i=0;i<size;i++){
sum+=array[i];
}
sum=sum/size;
printf("%f\n",sum);

system("pause");






}