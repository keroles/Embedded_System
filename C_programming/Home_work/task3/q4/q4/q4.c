#include"stdio.h"
int main()
{
	int a[5],i;
	printf("enter element of arrrrrray\n");
	
	for(i=1;i<=5;i++){
	scanf("%d",&a[i]);
	if(i==2){
		a[i]=a[i]>>4;
		a[i]=6;}

	
	}
	for(i=1;i<=5;i++)

	printf("///////////////%d\n",a[i]);

	
	system("pause");
}
