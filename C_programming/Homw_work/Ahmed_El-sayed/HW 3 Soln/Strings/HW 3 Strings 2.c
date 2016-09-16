#include "stdio.h"

void main(){
	char a[100],i;
	printf("Enter a string: ");
	gets(a);
	for(i=0;a[i] != 0;i++);
	printf("length of string: %d",i);
	system("pause");
}