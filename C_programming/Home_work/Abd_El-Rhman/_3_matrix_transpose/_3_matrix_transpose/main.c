#include"stdio.h"
int main(){
	int rows ,column,array[100][100],i,j;
	printf("Enter the number of rows:");
         scanf(" %d",&rows);
		 printf("Enter the number of column:");
		 scanf(" %d",&column);

printf("Enter the elements of matrix\n");
for(i=0;i<rows;i++){
	for(j=0;j<column;j++){
		printf("a%d%d:",i+1,j+1);
		scanf(" %d",&array[i][j]);}}

		
printf("The transpose of matrix is \n");
for(i=0;i<rows;i++){
	for(j=0;j<column;j++){
		printf("%d\t",array[j][i]);}
printf("\n");}

system("pause");

}