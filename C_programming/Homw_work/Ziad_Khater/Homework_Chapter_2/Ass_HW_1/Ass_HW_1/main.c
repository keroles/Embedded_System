
#include "stdio.h"
#include "conio.h"
void main()
{

   while(1)
   {
       int num;
       printf("Enter an integer you want to check :");
       scanf("%d",&num);
       if((num%2)==0)
        printf("%d is even.\n",num);
       else
        printf("%d is odd.\n",num);

   }
}
