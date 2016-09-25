#include"stdio.h"
#include"conio.h"

int main()
{
	char string[40];
	int i,len;
	printf("enter yr string \n");
	gets(string);
	len=strlen(string)-1;
	printf("length =%d\n",len);
	printf("reverse of string: ");
		for(i=len;i>=0;i--)
			printf(" %c",string[i]);
	printf("\n");
	system("pause");
}
