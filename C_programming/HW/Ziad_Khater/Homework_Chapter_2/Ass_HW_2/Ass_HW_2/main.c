
#include "stdio.h"
#include "conio.h"
void main()
{

   while(1)
   {
       char alph;
       printf("Enter an alphabet:");
       alph=getche();
       if(alph=='a'||alph=='e'||alph=='i'||alph=='o'||alph=='u')
        printf("\n%c is a vowel.\n",alph);
       else
        printf("\n%c is a consonant.\n",alph);
   }
}