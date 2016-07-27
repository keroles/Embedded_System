#include"stdio.h"
int main()
{
	float a[6],sum=0,avg=0;
	int i;
	printf("element of arrray\n");
	for(i=1;i<=6;i++)
	{
		printf("a%d=",i);
		scanf("%f",&a[i]);
		printf("\n");
		sum+=a[i];
	}
	printf("sum=%f\n",sum);
	avg=sum/6;
	printf("avg=%f\n",avg);
	system("pause");
}








