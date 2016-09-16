#include <stdio.h>
#include <conio.h>
void main ()
{
	char t , a[50] ;
	int i, j = 0;
	printf("Enter a sreing : ");
	gets(a);
	 i = 0;
   j = strlen(a) - 1;
 
   while (i < j) {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
      i++;
      j--;
   }
	printf("Its revers is : %s",a);

	getch();
}