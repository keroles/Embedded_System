#include"stdio.h"
int main(){
 int range1,range2,i,j;
 int flag=0,show=0;
 printf("Enter the two ranges:");
 scanf(" %d %d",&range1,&range2);

 for(i=range1+1;i<range2;i++){
	 for(j=2;j<i;j++){if(i%j==0&&j!=i){flag=1;}}
	 if(flag==0){printf("%d\n",i);
	 show++;}
	 flag=0;}
 if(show==0){printf("no prime between them\n");}
system("pause");

}



