#include <stdio.h>
#include <stdlib.h>
int power (int ,int);
int main()
{
    int x,y;
    printf("Enter your 2 number\n");
    scanf(" %d %d",&x,&y);

  int z=power(x,y);
  printf("%d",z);
    return 0;
}
int power(int x,int y){
if(y==0){return 1;}
else return x*power(x,y-1);


}
