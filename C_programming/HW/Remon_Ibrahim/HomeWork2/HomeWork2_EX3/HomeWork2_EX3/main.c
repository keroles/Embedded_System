#include<stdio.h>
#include<conio.h>

void main ()
{
	float x , y , z , max  ;
	printf("Enter three numbers : ");
	scanf("%f %f %f",&x,&y,&z);
	max = ( x > y ) ?( (x>z) ? x : z ): ( (y>z)? y: z) ;
	printf("Largest number = %f",max);
	getch();
}