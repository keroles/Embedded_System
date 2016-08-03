#include <stdio.h>
#include <stdlib.h>
int  factorial(int);
int main()
{
  int x,result;
  printf("Enter the number : ");
  scanf(" %d",&x);
  result=factorial(x);
  printf("the answer is %d\n",result);
  system ("pause");

}
 int factorial(int z){

 if (z==0){return 1;}
 else return z*factorial(z-1);

 }
