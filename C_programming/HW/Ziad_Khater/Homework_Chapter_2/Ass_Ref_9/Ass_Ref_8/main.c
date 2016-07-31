#include "stdio.h"
#include "conio.h"
void main()
{
    int c;
   while(1)
   {
       c=getche();
       if (c=='b')
        c=getche();
        if (c=='y')
            c=getche();
        if(c=='b')
            c=getche();
        if (c=='y')
        printf("\n\nGoodbye\n");
   }
}