#include "stdio.h"
#include "conio.h"
#include "string.h"
void main(){
	char text[100], c[1];
	int i, flag = 0;
	printf("enter sentence \n");
	gets(text);
	printf("enter character you want to check its frequenncy \n");
	gets(c);
	for(i=0; i<100; i++){
		if(c[0] == text[i]){
			flag++ ;
		}
	}
	printf(" %d times \n", flag);
	system("pause");
}