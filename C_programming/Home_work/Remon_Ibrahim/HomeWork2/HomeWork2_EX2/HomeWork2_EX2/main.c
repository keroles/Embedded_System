#include<stdio.h>
#include<conio.h>

void main ()
{
	char ch ; 
	printf("Enter an alphapet : ");
	scanf("%c",&ch);
	switch(ch)
	{
	case 'a' : case 'A' :
	case 'e' : case 'E' :
	case 'o' : case 'O' :
	case 'i' : case 'I' :
	case 'u' : case 'U' :
		{
			printf("%c is a vowel.",ch);
			break ;
		}
	default :
		{
			printf("%c is a constant.",ch);
			break;
		}

	}
	getch();
}