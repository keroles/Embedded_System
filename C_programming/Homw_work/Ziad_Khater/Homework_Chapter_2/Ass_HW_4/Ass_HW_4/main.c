
#include "stdio.h"
#include "math.h"
void main()
{
    float num;
    while(1)
    {
    printf("Enter a number: ");
    scanf("%f",&num);
   if(num>0)
    printf("%f is positive.\n",num);
   else if(num<0)
    printf("%f is Negative.\n",num);
   else
     printf("you entered zero\n");

    }
}