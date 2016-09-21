#include"stdio.h"
int main()
{
	int i;
	char character;
	
	printf("plz enter a character: ");
	scanf("%c",&character);
	i=character;
		if((i>=65)&(i<+90))
			printf("character is alphabet\n");
		else if((i>=97)&(i<=122))
			printf("character is alphabet\n");	
		else
			printf("character is not alphabet\n");
	
	system("pause");
}
	