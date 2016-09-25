#include <stdio.h>

int main()
{
    int i, j;
    printf("*    :");
    for( i= 1 ; i< 8 ; i++ )
        printf("    %d", i);

    printf("\n");

    for( i= 0; i< 50 ; i++)
        printf("-");

    printf("\n");

    for(i= 1 ; i< 8 ; i++)
    {
        printf("%d    :    ", i);
        for(j= 1; j< 8 ; j++)
            printf("%-5d", j*i);
        printf("\n");
    }

    return 0;
}
