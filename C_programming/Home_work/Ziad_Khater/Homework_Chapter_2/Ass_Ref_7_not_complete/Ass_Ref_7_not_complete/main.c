#include "stdio.h"
#include "conio.h"
void main()
{
    int i,j,k;

    for(i=1;i<=7;i++)
   {
    if(i==1){}
    else
    printf("%d\t:\t",i);

    for(j=1;j<=7;j++)
    {
           if(i==1 && j==1)
           {
               printf("*\t:\t%d\t",j);
           }
            else
            printf("%d \t",i*j);

    }
       printf("\n");

   }


}