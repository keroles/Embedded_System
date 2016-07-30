#include"stdio.h"
int main(){
	int array[100],size,i,desired,flag=0;
	printf("Enter the size of array:");
	scanf(" %d",&size); 
	printf("Enter the elements of array\n");
	for(i=0;i<size;i++){
		printf("a%d:",i+1);
		scanf(" %d",&array[i]);}

	printf("Enter the element that you want to search:");

      scanf(" %d",&desired);
	  for(i=0;i<size;i++){
		  if(desired==array[i]){printf("the elements is found in loc a%d\n",i+1);
		  flag=1;
		  break;}}
	  if(flag==0){printf("the element not found\n");}
	  system("pause");
}
