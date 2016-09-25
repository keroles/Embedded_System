#include "stdio.h"
#include "conio.h"
#define r 100

void main(){
    
    int i,L=0;
    char string[r],reverse[r];
    
	printf("Enter a string : ");
    gets(string);
    L = strlen(string);
	for(i=0;i<L;i++){
		reverse[i] = string[L-i-1];
	}
	reverse[L] = 0;
    printf("Reverse string = %s \n",reverse);
    
    printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",i);
}