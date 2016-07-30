#include "stdio.h"
void main(){
	char letter;
	printf("enter character you want to check \n");
	scanf("%c", &letter);
	if(letter == 65 || letter == 97 || letter == 69 || letter == 101 || letter == 73 || letter == 105 || letter == 79 || letter == 111){
		printf("letter %c is a vowel \n", letter);
	}
	else{
		printf("letter %c is a consonant \n", letter);}
    system("pause");		
}
