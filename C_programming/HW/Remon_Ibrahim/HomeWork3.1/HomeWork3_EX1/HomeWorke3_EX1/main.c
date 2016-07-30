#include <stdio.h>
#include <conio.h>

void main( void )
{
	float a[2][2] , b[2][2] , s[2][2]  ;
	int i , j  ;
	printf("Enter all elements of first matrix :\n");
	for( i =0 ; i< 2 ; i++ )
	{
		for ( j= 0 ; j< 2 ; j++ )
		{
			printf("Enter a%d%d ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
	printf("Enter all elements of second matrix :\n");
	for( i =0 ; i< 2 ; i++ )
	{
		for ( j= 0 ; j< 2 ; j++ )
		{
			printf("Enter b%d%d ",i+1,j+1);
			scanf("%f",&b[i][j]);
		}
	}
	
	printf("Sum of matrix :\n");
	for( i =0 ; i< 2 ; i++ )
	{
		for ( j= 0 ; j< 2 ; j++ )
		{
			s[i][j]= a[i][j] + b[i][j] ;
			printf("%0.2f	",s[i][j]);
		}
		printf("\r\n");
	}
	getch();
}