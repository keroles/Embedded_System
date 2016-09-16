#include "stdio.h"

void main(){
	char a[100],ch1,ch2;
	int i, count=0;
	printf("Enter a string: ");
	gets(a);
	printf("Enter a character to find frequency: ");
	scanf(" %c",&ch1);
	if(ch1 > 64 && ch1 < 91){				//To include both capital and small in the search
		ch2 = ch1+32;
	}
	else if(ch1 > 96 && ch1 < 123){
		ch2 = ch1-32;
	}
	for(i=0;a[i]!=0;i++){
		if(a[i]== ch1 || a[i]== ch2){
			count++;
		}
	}
	printf("Frequency of %c: %d\n",ch1,count);
	system("pause");
}