#include"stdio.h"
int main()
{
	float a[2][2],b[2][2],c[2][2];
	int i,j;
	printf("plz enter the first arrrrrrrray:\n");
	for(i=1;i<=2;i++){
		for(j=1;j<=2;j++){
			printf("a%d%d= ",i,j);
			scanf("%f",&a[i][j]);
			printf("\n");
		}
	}
	printf("plz enter the second arrrrrrrray:\n");
	for(i=1;i<=2;i++){
		for(j=1;j<=2;j++){
			printf("b%d%d= ",i,j);
			scanf("%f",&b[i][j]);
			printf("\n");
		}
	}
	printf("summing arrrrray \n");
	for(i=1;i<=2;i++){
		for(j=1;j<=2;j++){
			c[i][j]=a[i][j]+b[i][j];
		printf("%f\t",c[i][j]);
		}
		printf("\n");
	}
	system("pause");
}






