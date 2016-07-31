/*
EX6:

Write Source Code to Swap Two Numbers

#########Console_output######
Enter value of a: 1.20
Enter value of b: 2.45

After swapping, value of a = 2.45
After swapping, value of b = 1.2
#############################
########################################################################
*/ 
#include "stdio.h"

void main()
{
    float x,y,z;
    printf("Enter x then y\n");
    scanf("%f%f",&x,&y);
    z=x;
    x=y;
    y=z;

    printf("x=%f y=%f",x,y);
}

