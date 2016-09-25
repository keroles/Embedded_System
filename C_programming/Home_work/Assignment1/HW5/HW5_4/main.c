#include <stdio.h>
#include <stdlib.h>

 struct student{
     char name [100];
     int roll;
     float mark;
                        };
int main()
{
    int i;
     struct student s1[10];
     for(i=0;i<10;i++){
            printf("student %d\n",i+1);

  printf("Enter roll number\n");
  scanf("%d",&s1[i].roll);
       printf("Enter your first name \n");
  gets(s1[i].name);
  gets(s1[i].name);
   printf("Enter mark\n");
   scanf("%f",&s1[i].mark);

    printf("\n");
     }

      for(i=0;i<10;i++){
               printf("student %d\n",i+1);
   printf("name is %s\n",s1[i].name);
   printf("roll is %d\n",s1[i].roll);
   printf("mark is %g\n",s1[i].mark);
     printf("\n");


      }
    return 0;
}
