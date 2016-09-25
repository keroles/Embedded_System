#include <stdio.h>
#include <stdlib.h>

int main()
{
    char alpha ;

    printf("Enter an alphabet: ");
    scanf("%c", &alpha);

    if( alpha>= 65 && alpha<= 90 || alpha>= 97 && alpha<= 122 )
        if( alpha== 'a' || alpha== 'u' || alpha== 'e' || alpha== 'o' || alpha== 'i' ||
            alpha== 'A' || alpha== 'U' || alpha== 'E' || alpha== 'O' || alpha== 'I'   )
            printf("%c is a vowel.", alpha);
        else
            printf("%c is a constant.", alpha);

    else
        printf("it is not alphabet.");

    return 0;
}
