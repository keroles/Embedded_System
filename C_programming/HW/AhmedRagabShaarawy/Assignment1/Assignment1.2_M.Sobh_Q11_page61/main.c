#include <stdio.h>

int main()
{
    unsigned int day, month, year, givenYear, daysNums= 1, i, trueDay= 0, trueMonth= 0 ;

    printf("Enter a date<dd mm yy>: ");
    scanf("%d %d %d", &day, &month, &year );
    printf("Enter a year: ");
    scanf("%d", &givenYear );

    trueDay= day> 0 &&( month== 1 &&  day<= 31 || month== 2  && day<= 29 || month== 3 &&  day<= 31 || month== 4  && day<= 30 ||
                        month== 5 &&  day<= 31 || month== 6  && day<= 30 || month== 7 &&  day<= 31 || month== 8  && day<= 31 ||
                        month== 9 &&  day<= 30 || month== 10 && day<= 31 || month== 11 && day<= 30 || month== 12 && day<= 31 );
    trueMonth= month>0 && month< 13 ;

/************** Days calculation from year ***************/
    if( year< 1 || givenYear< 1 )
    {   printf("Error!!Invalid year.");     goto End;   }
    i= givenYear;
    while( i != year && i != year+1 )
    {
        daysNums+= 365;
        if( i%4== 0 && i%400== 1 ) /// for leap year.
            daysNums++;

        if( year> givenYear)    i++;
        else if( year< givenYear )  i--;
    }
/************** Days calculation from month  *************/
    if( trueMonth )
    {
        i= month;
        while( i> 0 && i< 13 )
        {
            if( year>= givenYear ) i--;
            else if( year< givenYear ) i++;
            switch( i )
            {
                case 1 : case 3 : case 5 : case 7 :
                         case 8 : case 10: case 12: daysNums+= 31; break;
                case 2 : daysNums+= 28; break;
                case 4 : case 6 : case 9 : case 11: daysNums+= 30; break;
                default: break;
            }
        }
    }
    else
        {   printf("Error!!Invalid month.");  goto End;  }
/************* Days calculation from day **************/
    if( trueDay )
    {
        if( year>= givenYear)
            daysNums+= day;

        else if( year< givenYear )
        {
            switch(month)
            {
                case 1 : case 3 : case 5 : case 7 :
                         case 8 : case 10: case 12: daysNums+= 31-day; break;
                case 2 : daysNums+= 28-day; break;
                case 4 : case 6 : case 9 : case 11: daysNums+= 30-day; break;
                default: break;
            }
        }
    }
    else
    {   printf("Error!!Invalid day.");  goto End;   }

    if( month== 2 && i%4== 0 && i%400== 1 ) /// if this year is leap, and this month is February.
        daysNums++;
/********************** Printing **********************/
    printf("Days number = %d", daysNums);

    End: /***  if there is any false data ***/
    return 0;
}
