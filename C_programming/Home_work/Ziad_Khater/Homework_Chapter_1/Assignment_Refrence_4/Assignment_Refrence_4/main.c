#include "stdio.h"
void main()
{
    int x;
	while(1)
	{
	printf("Enter a number \n");
    scanf("%d",&x);
    if (x>96)  //first small character
        printf("The equivalent character is %c \n",x);
    else if (x<96)
        printf("The equivalent character is %C \n",x);
    else
        printf("This char is unknown\n");
	}
}