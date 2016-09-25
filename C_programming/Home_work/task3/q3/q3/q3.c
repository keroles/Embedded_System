#include"stdio.h"
int main()
{
	int a[2][3],b[3][2];
	int i,j;
	printf("enter the matrix\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
			
	}
	for(i=0;i<2;i++){
		for(j=0;j<3;j++)
			b[j][i]=a[i][j];}
	for(j=0;j<3;j++){
		for(i=0;i<2;i++){
			printf("%d\t",b[j][i]);

		}
		printf("\n");
	}
	system("pause");
}






