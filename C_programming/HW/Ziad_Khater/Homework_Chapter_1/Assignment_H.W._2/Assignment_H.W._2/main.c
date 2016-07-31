
/* Write C Program to Print a Integer Entered by a User
i should see the Console as following:
##########Console-output###
Enter an integer: 25
You entered: 25
###########################
*/


#include "stdio.h"

void main()
{
    int Num;
    printf("Enter An Intger :");
    scanf("%d",&Num);
    printf("You Entered : %d",Num);
}