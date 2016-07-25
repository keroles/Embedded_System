#include <stdio.h>
#define SIZE 100

int main()
{
    float arr[SIZE], average= 0;
    int  n, i;
    printf("This program calculates\nthe average of n(max 200) numbers:.\n");
    printf("Enter the n numbers( max 200 ): ");
    scanf("%d", &n);
    if( n> SIZE)
		printf("The n numbers exceeds the maximum !.");

    else {
    for( i= 0; i< n ; i++)
    {
        printf("Enter number%d: ", i+1);
        scanf("%f", &arr[i]);
        average+= arr[i];
    }

    printf("The average of the numbers = %lg", average/n);
    }


    return 0;
}
