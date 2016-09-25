#include"stdio.h"
int main()
{
	char letter;
	printf("enter an alphabet :");
	scanf("%c",&letter);
	printf("%c",letter);
	if((letter=='a')|(letter=='i')|(letter=='u')|(letter=='e')|(letter=='o'))
		printf("is a vowel\n");
	else
		printf("is a consonant\n);
		system("pause");
}