#include <stdio.h>
#include <stdlib.h>
#define SIZE1 48
int main()
{
    char sent[SIZE1]={'H','e','l','l','o',' ','E','n','g',' ','K', 'e', 'r', 'o', 'l', 'o', 's',
                    '\n','I', ' ', 'a', 'm', ' ', 'A', 'h', 'm', 'e', 'd', '\n',
                    'N', 'i', 'c', ' ', 't', 'o', ' ', 'm', 'e', 'e', 't', ' ', 'y', 'o', 'u'};
    int i;

    for( i= 0 ; i< SIZE1 ; i++ )
        printf("%c", sent[i] );

    return 0;
}
