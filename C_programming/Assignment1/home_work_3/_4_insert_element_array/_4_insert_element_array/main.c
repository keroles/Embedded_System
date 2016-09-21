#include"stdio.h"
int  main(){
	int size,location,inserted,i,array[100]={0};
	printf("Enter the number of elements:");
          scanf(" %d",&size);

	for(i=0;i<size;i++){
		array[i]=i+1;}
	printf("The elements are  ");
	
	for(i=0;i<size;i++){
		printf(" %d   ",array[i]);}
	
	printf("\n");

	printf("enter element that u want to insert :");
	scanf(" %d",&inserted);
lable:
	printf("enter location that u want to insert in :");
	scanf(" %d",&location);
	if(location>size||location<=0){printf("\nyou can only choose location from 1 to %d\n ",size);
	goto lable;}
	array[location-1]=inserted;


printf("The elements after changed are   ");
	
	for(i=0;i<size;i++){
		printf(" %d   ",array[i]);}





	printf("\n");
	system("pause");
}