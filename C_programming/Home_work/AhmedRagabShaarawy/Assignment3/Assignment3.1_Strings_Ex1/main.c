#include <stdio.h>
#define SIZE 201
#define ALPHA_SIZE 26

int main()
{
    unsigned char str[SIZE]={0}, alpha[ALPHA_SIZE]={0}, chrctr, i, litter, freq= 0;

    printf("============================================\n\n         (I) THE REQUIRED PROGRAM SOLUTION IN HW: \n\n");
    printf("<200 characters allowed after that will neglected>\nEnter a sentence: ");
    gets(str);
    printf("Enter a litter to find it's frequency: ");
    scanf("%c", &litter);
    for( i= 0; str[i]!= 0 ; i++)
    {
        if( str[i]== litter)
            freq++;
        for( chrctr= 'a' ; chrctr<= 'z' ; chrctr++)
            if( str[i]== chrctr || str[i]== chrctr-('a'-'A') )
                alpha[chrctr-'a']++;
    }

    printf("frequency of %c= %d\n\n\n", litter, freq);

    printf("============================================\n\n         (II) EXTENDED PROGRAM SOLUTION: \n\n\n\n");
    for( i= 0 ; i< ALPHA_SIZE ; i++)
    {
        if(alpha[i]!= 0 )
            printf("Frequency of %c & %c= %d\n", i+'a', i+'A', alpha[i]);
    }
    printf("\n\nTHANK YOU,\nWISHES GOOD LUCK,\n\n\n          PREPARED BY AHMED SHAARAWY.\n            ======================\n\n");


    //printf("Hello world!\n");
    return 0;
}
