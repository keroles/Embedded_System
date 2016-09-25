#include <stdio.h>
#include <stdlib.h>
struct Complex{
float real;
float comp; };

struct Complex ADD( struct Complex s1,struct Complex s2){
 struct Complex s3;
 s3.real=s1.real+s2.real;
 s3.comp=s1.comp+s2.comp;
return s3;
}

int main()
{
struct Complex s1,s2,s3;
printf("Enter the Fist Complex number \n");
scanf("%f %f",&s1.real,&s1.comp);
printf("Enter the 2nd Complex number \n");
scanf("%f %f",&s2.real,&s2.comp);
s3=ADD(s1,s2);
printf("the answer is %g+%gi ",s3.real,s3.comp);

}
