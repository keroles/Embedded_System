#include<stdio.h>
#define PAUSE while(1)


main()
{
	int matrix1[2][2], matrix2[2][2], i, j;
	long total[2][2]= {0};
	printf("Enter first matrx:\n");
	for( i= 0 ; i< 2 ; i++)
		for( j= 0 ; j< 2; j++ )
		{
			printf("Element%d%d: ", i+1, j+1);
			scanf("%d", &matrix1[i][j]);
		}
	
	printf("\nEnter second matrx:\n");
	for( i= 0 ; i< 2 ; i++)
		for( j= 0 ; j< 2; j++ )
		{
			printf("Element%d%d: ", i+1, j+1);
			scanf("%d", &matrix2[i][j]);
		}

	for( i= 0 ; i< 2 ; i++)
		for( j= 0 ; j< 2; j++ )
			total[i][j]= (long)(matrix1[i][j]+ matrix2[i][j]);
	
	printf("\nSum of matrices:\n");
	for( i= 0 ; i< 2 ; i++)
	{
		for( j= 0 ; j< 2; j++ )
			printf("%d    ", total[i][j]);
		printf("\n\n");
	}


	PAUSE;
}