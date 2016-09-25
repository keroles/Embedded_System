#include"stdio.h"
int main(){
    char str[100];
	int count=0;
	int i;
	char ch;
	printf("Enter u phrase here:");
	gets(str);

	printf("Enter the character that u want to count in this phrase:");
    scanf(" %c",&ch);
	for(i=0;i<100;i++){
		if(ch==str[i]){count++;}
		else if(str[i]=='\0'&&count>0){printf("the number is %d\n",count);
		break;
		}
		
}
	if (count==0){printf("The character is not here\n");}

system("pause");
}