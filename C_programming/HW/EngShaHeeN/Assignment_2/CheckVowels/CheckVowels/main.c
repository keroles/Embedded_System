#include "stdio.h"

void main(){
    
    char n;
    
	printf("Enter an alphabet you want to check : ");
    scanf("%c",&n);
	
	if ((n=='a')||(n=='e')||(n=='i')||(n=='o')||(n=='u')){
		printf("%c is a VOWEL",n);
	}
	else{
		printf("%c is a CONSONANT",n);
	}
	printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",n);
}