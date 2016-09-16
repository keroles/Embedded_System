#include "stdio.h"
#include "conio.h"
#define r 100

void main(){
    
    int i,counter=0;
	char c;
    char string[r];
    
	printf("Enter a string : ");
    gets(string);
    
    for(i=0;i<r;i++){
		if (string[i] == 0){
           break; 
        }
		counter++;
	} 
    printf("Length of string = %d \n",counter);
    
    printf("\n\n####################\nPress any key to exit\n####################\n");
	scanf("%d",i);
}