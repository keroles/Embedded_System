/* EX5:

Write C Program to Find ASCII Value of a Character

#########Console_output######
Enter a character: G
ASCII value of G = 71
#############################


########################################################################

*/

#include "stdio.h"

void main()
{
    char x;
    printf("Enter A Character :\n");
    scanf("%c",&x);
    printf("ASCI Value of %c : %d",x,x);
}