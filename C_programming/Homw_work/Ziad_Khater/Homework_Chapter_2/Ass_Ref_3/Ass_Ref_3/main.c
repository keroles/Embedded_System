
#include "stdio.h"
#include "math.h"
void main()
{
    int num1,num2,num3;
    int max;
    while(1)
    {
    printf("Enter 3 numbers \n");
    scanf("%d%d%d",&num1,&num2,&num3);
    max=(num1>num2)?num1:(num2>num3)?num2:num3;

    printf("Max num is %d\n",max);

    }
}
