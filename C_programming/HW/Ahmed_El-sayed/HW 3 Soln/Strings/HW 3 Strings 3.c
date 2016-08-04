#include "stdio.h"
#include "string.h"

void main(){
	char a[100],i;
	printf("Enter a string: ");
	gets(a);
	printf("Reverse string is: ");
	for(i=strlen(a)-1;i>=0;i--){
		printf("%c",a[i]);
	}
	printf("\n");
	system("pause");
}