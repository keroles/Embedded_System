#include"stdio.h"
#include"string.h"
int main(){
int i,length;
char str[100];
printf("Enter your phrase here:");
gets(str);
printf("\n\n");
printf("the phrase after reversed:");
length=strlen(str);
for(i=length-1;i>=0;i--){
	printf("%c",str[i]);
}
printf("\n\n");
system("pause");}