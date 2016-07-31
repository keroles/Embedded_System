/*EX7:
it is an interview trick

Write Source Code to Swap Two Numbers without temp variable.
*/ 

#include "stdio.h"

void main()
{
    float x,y;
    printf("Enter x then y\n");
    scanf("%f%f",&x,&y);
    x=x+y;  // if x = 1 y=2  then x =3
    y=x-y;  // y = 1
    x=x-y;  // x= 3-1 =2

    printf("x=%f y=%f",x,y);
}
