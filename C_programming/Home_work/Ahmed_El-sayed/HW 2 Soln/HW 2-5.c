#include "stdio.h"

void main(){
	unsigned char alpha;
	printf("Enter a character: ");
	scanf(" %c",&alpha);
	if( (alpha >= 65 && alpha <= 90) || (alpha >= 97 && alpha <= 122) ){
		printf("%c is an alphabet.\n",alpha);
	}
	else{
		printf("%c is not an alphabet.\n",alpha);
	}
	system("pause");

}