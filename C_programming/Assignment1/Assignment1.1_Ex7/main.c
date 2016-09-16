#include <stdio.h>
#include <stdlib.h>


int main()
{

    float a, b;
   /// int a, b ; /// step one,  used for xor swap, second way.

/**** note when using float in this swapping way the result of swapping has an error value,
***** note that if the two number is too big the will make an over flow in step two  */
    printf("Enter value of a: ");
    scanf("%f", &a);
    printf("Enter value of b: ");
    scanf("%f", &b);


    a= a+b ; /// step two .
    b= a-b ;
    a= a-b ;

/**** A second way to use.
***** the problem in this way is that it works only with integers
***** so you must make a & b integer in step one and alter the type
***** of scan to "%d or %i" and alter type of print to "%d or %i" in step 3  */
/****
    a= b^a;
    b= b^a;
    a= b^a;
    */


    printf("After swapping, value of a = %f\n", a); /// step 3.
    printf("After swapping, value of b = %f", b);   /// step 3.

    return 0;
}
