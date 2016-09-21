#include"stdio.h"
int main(){
	int i,j;
float array[2][2],array1[2][2],array2[2][2];
printf("Enter elemnts of first 2*2 matrix\n");
for(i=0;i<2;i++){
	for(j=0;j<2;j++){
		printf("a%d%d:",i+1,j+1);
		scanf(" %f",&array[i][j]);
	}
}

printf("Enter elemnts of Second 2*2 matrix\n");
for(i=0;i<2;i++){
	for(j=0;j<2;j++){
			printf("a%d%d:",i+1,j+1);
		scanf(" %f",&array1[i][j]);
	}
}

for(i=0;i<2;i++){
	for(j=0;j<2;j++){
		array2[i][j]=array[i][j]+array1[i][j];}
}

printf("the summition of two matrix is\n");

for(i=0;i<2;i++){
	for(j=0;j<2;j++){
		printf("%f\t",array2[i][j]);}
	printf("\n");}



system("pause");


}













