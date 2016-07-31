
#include "stdio.h"
#include "math.h"
void main()
{
    int num1,num2,num3,num4;
    while(1)
    {
    printf("Enter 4 numbers \n");
    scanf("%d%d%d%d",&num1,&num2,&num3,&num4);
    if (num1>num2 && num1>num3 && num1>num4)
        printf("number %d is the max number \n",num1);
    else if (num2>num1 && num2>num3 && num2>num4)
        printf("number %d is the max number \n",num2);
    else if (num3>num1 && num3>num2 && num3>num4)
        printf("number %d is the max number \n",num3);
    else if (num4>num1 && num4>num2 && num4>num3)
        printf("number %d is the max number \n",num4);
    else printf("There are more than Max number with the same value \n");
    }
}
