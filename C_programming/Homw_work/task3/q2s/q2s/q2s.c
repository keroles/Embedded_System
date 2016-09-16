#include"stdio.h"
int main()
{
	char string[40];
	int i=0,num=0;
	printf("enter yr string\n");
	gets(string);
	while(string[i]!='\0')
	{
		num+=1;
		i++;
	}
	printf("length of string= %d\n",num);


	system("pause");
}