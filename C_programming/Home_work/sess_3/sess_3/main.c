#include"stdio.h"
#include"conio.h"
int main(){
int i;
	char str[100],str1[100],str2[100];
	printf("Enter the first name\n");
	gets(str);
	printf("Enter the second name\n");
	gets(str1);

	for(i=0;i<100;i++){
       str2[i]=str[i];
	   str[i]=str1[i];
	   str1[i]=str2[i];}
	printf("\nthe two names after swaping are \n");
	printf("%s \n%s\n",str,str1);

system("pause");
}
