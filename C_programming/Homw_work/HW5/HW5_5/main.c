#include <stdio.h>
#include <stdlib.h>

#define area(x) (3.14*x*x)

int main()
{
float r;
 printf("Enter the radius of circle\n");
 scanf("%f",&r);
 printf("the area is %g\n",area(r));
}
