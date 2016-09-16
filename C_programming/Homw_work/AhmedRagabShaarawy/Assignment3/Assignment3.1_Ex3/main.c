#include <stdio.h>
#define ROWS    50
#define COLUMNS 50

int main()
{
    float mat[ROWS][COLUMNS], temp;
    int i, j  ,rows, columns, largest= 0;

    printf("Enter matrix rows (max 100): ");
    scanf("%d", &rows);
    printf("Enter matrix columns (max 100): ");
    scanf("%d", &columns);
    if( rows<= ROWS && columns<= COLUMNS )
    {

        largest= rows> columns ? rows: columns;

        for(i= 0; i< rows ; i++)
            for(j= 0 ; j< columns ; j++)
            {
                printf("Enter the element%d%d: ", i+1, j+1);
                scanf("%f", &mat[i][j]);
            }

        printf("You entered: \n");
        for(i= 0; i< rows ; i++){
            for(j= 0 ; j< columns ; j++)
                printf("%lg    ",mat[i][j]);
        printf("\n\n");
        }


        for( i= 0; i< largest ; i++)
            for( j= i ; j< largest ; j++)
            {
                temp= mat[i][j];
                mat[i][j]= mat[j][i];
                mat[j][i]= temp;
            }


        printf("The matrix transpose is: \n");
        for(j= 0; j< columns ; j++){
            for(i= 0 ; i< rows ; i++)
                printf("%lg    ",mat[j][i]);
            printf("\n\n");
        }
    }
    else
        printf("The rows or columns exceeds the max!.");

    return 0;
}
