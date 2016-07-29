#include <stdio.h>
#include <conio.h>

void main ()
{
	char ch ,a[50] ;
	int c = 0 ,i ;
	printf("Enter a string :  ");
	gets(a);
	printf("Enter a charcter : ");
	scanf("%c",&ch);
	for(i=0 ; i<strlen(a) ;i++ )
	{
		if ( a[i] == ch )
			c++;
	}
	printf("It occure %d times",c);
	getch();
}