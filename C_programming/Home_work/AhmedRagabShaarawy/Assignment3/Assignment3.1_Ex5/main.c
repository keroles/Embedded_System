#include <stdio.h>
#define SIZE 200

int main()
{
    float arr[SIZE], value ;
    int i, n, flag= 0;
    printf("Enter number of elements(max 200): ");
    scanf("%d", &n);
    if( n<= SIZE)
    {
        printf("Enter the elements: \n");
        for( i= 0; i< n ; i++)
        {
            printf("Enter element%d: ", i+1);
            scanf("%f", &arr[i]);
        }
        printf("Enter element to search: ");
        scanf("%f", &value);
        for( i= 0; i< n ; i++)
        {
            if( arr[i]== value)
            {
                flag= 1;
                printf("Number found at location (%d) ", i+1);
                break;
            }
        }

        if( flag == 0)
            printf("Number not found");
    }
    else
        printf("The number of elements exceeds the max!.");

    return 0;
}
