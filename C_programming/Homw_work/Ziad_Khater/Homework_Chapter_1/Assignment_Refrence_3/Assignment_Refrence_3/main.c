#include "stdio.h"
void main()
{
    double distance;
    printf("Enter the distance in feets \n");
    scanf("%lf",&distance);
    printf("distance in meters= %lf",distance * 0.3048);
    printf(" meter");
}