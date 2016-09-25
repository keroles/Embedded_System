#include"stdio.h"
int main()
{
	int x,y,z;
	printf(" enter the 3 nums :\n");
	scanf("%d %d ",&x,&y);
	scanf("%d",&z);
	printf("the largest num is : ");
	if((x>y)&(x>z))
		printf("%d",x);
	else if((y>x)&(y>z))
		printf("%d",y);
	else
		printf("%d",z);
	printf("\n");
	system("pause");
}
