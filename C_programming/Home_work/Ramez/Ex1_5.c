#include "stdio.h"
void main(){
	char letter;
	printf("enter a character \n");
	scanf("%c", &letter);
	printf("ASCII value of %c is %d \n", letter, letter);
	system("pause");
}