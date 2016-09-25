#include <stdio.h>
#include <stdlib.h>

 struct student{
     char name [100];
     int roll;
     float mark;
                        };
int main()
{  struct student s1;
  printf("Enter your first name \n");
  gets(s1.name);
  printf("Enter roll number\n");
  scanf("%d",&s1.roll);
   printf("Enter mark\n");
   scanf("%f",&s1.mark);

   printf("name is %s\n",s1.name);
   printf("roll is %d\n",s1.roll);
   printf("mark is %g\n",s1.mark);
   system("pause");


    return 0;
}
