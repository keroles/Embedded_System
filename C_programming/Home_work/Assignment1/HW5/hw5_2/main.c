#include <stdio.h>
#include <stdlib.h>
struct conv_add{
int feet;
float inches;
};
int main()
{ int y;
float z;
    struct conv_add s1,s2;
 printf("Enter 1st foot \n");
 scanf("%d",&s1.feet);
  printf("Enter 1st inche \n");
  scanf("%f",&s1.inches);


 printf("Enter 2nd foot \n");
 scanf("%d",&s2.feet);
  printf("Enter 2nd inche \n");
  scanf("%f",&s2.inches);

if((s1.inches+s2.inches)>=12){
        z=(s1.inches+s2.inches)/12;

        y=(int) z;// +feet
   if((s1.inches+s2.inches)<13){ z=(z-y)*12;}//+inches
   else z=z-y;
        printf("The sum of distances is %g inches\n",s1.feet+s2.feet+y+z);
}


else {
    printf("The sum of distances is %g inches \n",s1.feet+s2.feet+((s1.inches+s2.inches)/12));
}



    return 0;
}
