#include <stdio.h>
#include <conio.h>

void main ()
{
	char ch ;
	printf("Enter a charachter : ");
	scanf("%c",&ch);
	if ( ( ch >='a' && ch <='z' ) || ( ch >='A' && ch <='Z') )
		printf("%c is an alphapet.", ch);
	else
		printf("%c is not an alphapet.", ch);
	getch();
}
