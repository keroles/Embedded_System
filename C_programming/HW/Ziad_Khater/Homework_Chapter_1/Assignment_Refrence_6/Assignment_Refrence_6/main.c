#include "stdio.h"
#include "conio.h"
#include "math.h"
void main()
{
    float x,y,z;
    float result;
    while(1)
    {
    printf("Enter x/y/z in this form: \n");
    scanf("%f/%f/%f",&x,&y,&z);
    result = (x+sqrt(exp(pow(x,0.2))+((x*x)+(y*y*y))))/sin(x/(z*10.5))+pow(z,5.5);
    printf("The result equals = %f \n",result);
    }
}