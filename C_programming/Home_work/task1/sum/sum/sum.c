#include"stdio.h"
int main()
{
	int n,i;
	int sum=0;
	printf("enter yr n num : ");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		sum+=i;
	printf("\nsum =%d\n",sum);

system("pause");
}
