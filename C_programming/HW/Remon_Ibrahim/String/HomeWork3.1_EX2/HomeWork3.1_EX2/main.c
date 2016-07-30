#include <stdio.h>
#include <conio.h>
void main ()
{
	char a[50];
	int i = 0, c = 0 ;
	printf("Enter a string : ");
	gets(a);
	while ( a[i++] != '\0' )
	{
		c++;
	}
	printf("Length is %d ",c);

	getch();

}