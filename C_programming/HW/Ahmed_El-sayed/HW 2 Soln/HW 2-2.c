#include "stdio.h"

void main(){
	unsigned char x;
	printf("Enter an alphabet: ");
	scanf(" %c",&x);
	switch(x){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
				 printf("%c is a vowel.\n",x);
				 break;
		default:
				 printf("%c is a consonant.\n",x);
	}
	system("pause");
	
	
}