#include "stdio.h"
void main()
{
    float weight;
    printf("Enter your weight in pounds ");
    scanf("%f",&weight);
    printf("Your weight in kilograms is %f",weight * 0.45359237);
}