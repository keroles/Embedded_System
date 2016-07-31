

/* 
EX4

Write C Program to Multiply two Floating Point Numbers
i should see the Console as following:
##########Console-output###

###########################
Enter two numbers: 2.4
1.1
Product: 2.640000
########################################################################


*/

#include "stdio.h"

void main()
{
    float Num1,Num2;
    printf("Enter Two Numbers :\n");
    scanf("%f%f",&Num1,&Num2);
    printf("Product : %0.6f",Num1*Num2);
}