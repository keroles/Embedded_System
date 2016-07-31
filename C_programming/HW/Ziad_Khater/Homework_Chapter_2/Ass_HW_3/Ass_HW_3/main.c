

#include "stdio.h"
#include "math.h"
void main()
{
    float num1,num2,num3;
    float max;
    while(1)
    {
    printf("Enter three numbers:");
    scanf("%f%f%f",&num1,&num2,&num3);
    max=(num1>num2)?num1:(num2>num3)?num2:num3;

    printf("largest number = %f\n",max);

    }
}