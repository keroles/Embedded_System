#include"stdio.h"
int main()
{
	int a[5],i,num;
	printf("element of arrrrrrrray \n");
	for(i=1;i<=5;i++)
		scanf("%d",&a[i]);
	printf(" num you are search about it = ");
	scanf("%d",&num);
	for(i=1;i<=5;i++)
		if(a[i]==num)
			printf("the location =%d\n",i);
			printf("num you are searched about it= %d\n",num);
		
	system("pause");
}