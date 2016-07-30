#include "stdio.h"
void main(){
	char letter;
	int i, flag=0;
	printf("enter character you want to check\n");
	scanf("%c", &letter);

	for(i=65; i<=90; i++){
		if(letter == i){
			flag = 1;}}
	for(i=97; i<=122; i++){
		if(letter == i){
			flag = 1;}}
	if(flag == 1){
		printf("character %c is alphabet \n", letter);
	}
	else if(flag == 0){
		printf("character %c is not alphabet \n", letter);
	}
	system("pause");
}