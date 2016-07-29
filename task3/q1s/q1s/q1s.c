#include"string.h"
#include"conio.h"
int main()
{
	char string[40],character;
	int i=0;
		int num=0,len;
	printf("enter yr string \n");
	gets(string);
	printf("enter yr character\n");
	scanf("%c",&character);
	len=strlen(string)-1;
	printf("len=%d\n",len);
	for(i=0;i<=len;i++)
	{
		if(string[i]==character)
			num+=1;
			
	}
	printf("frequency of %c",character);
	printf("=%d\n",num);
	

system("pause");
}

