#include <stdio.h>
#define  SIZE 201

int main()
{
    float arr[SIZE], insert ;
    int i, location, n ;
    printf("Enter number of elements(max 200): ");
    scanf("%d", &n);


    if( n<= SIZE-1)
    {
        for( i= 0; i< n ; i++)
        {
            printf("Enter element%d: ", i+1);
            scanf("%f", &arr[i]);
        }

        printf("Enter the insertion element: ");
        scanf("%f", &insert);
        printf("Enter the location: ");
        scanf("%d", &location);

        for( i= n-1 ; i>= location-1 ; i--)
            arr[i+1]= arr[i];

        arr[location-1]= insert;

        for( i= 0; i< n+1 ; i++)
            printf("%lg    ", arr[i]);
    }
    else
        printf("Number of elements exceed the max!.");

    return 0;
}
