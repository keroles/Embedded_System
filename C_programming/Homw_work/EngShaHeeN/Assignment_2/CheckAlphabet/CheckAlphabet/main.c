#include "stdio.h"

void main(){
	char c;
	printf("Enter a character: ");
	scanf("%c",&c);
	if( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
		printf("%c is an alphabet\n",c);
	}
	else{
		printf("%c is not an alphabet\n",c);
	}
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",c);

}