#include "stdio.h"
#include "conio.h"
#define r 100

void main(){
    
    int i,f=0;
	char c;
    char string[r];
    
	printf("Enter a string : ");
    gets(string);
    
	printf("Enter a character to find frequency : ");
    scanf("%c",&c);
    

	//copying
    
    for(i=0;i<r;i++){
        if(string[i] == c){
           f++; 
        }
		else if (string[i] == 0){
           break; 
        }
	} 
    printf("Frequency of %c = %d \n",c,f);
    
    printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",i);
}