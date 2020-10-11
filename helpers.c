#include <strings.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// the Tomohiko Sakamoto Algorithm
int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

int firstDay(int m, int y)
{
    if (m < 3) y -= 1;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + 1) % 7;
}

// returns the month's number
int findMonth(char *m)
{
    if (strcasecmp(m, "January") == 0) return 1;
    if (strcasecmp(m, "February") == 0) return 2;
    if (strcasecmp(m, "March") == 0) return 3;
    if (strcasecmp(m, "April") == 0) return 4;
    if (strcasecmp(m, "May") == 0) return 5;
    if (strcasecmp(m, "June") == 0) return 6;
    if (strcasecmp(m, "July") == 0) return 7;
    if (strcasecmp(m, "August") == 0) return 8;
    if (strcasecmp(m, "September") == 0) return 9;
    if (strcasecmp(m, "October") == 0) return 10;
    if (strcasecmp(m, "November") == 0) return 11;
    if (strcasecmp(m, "December") == 0) return 12;
    else return -1;
}

// returns number of days in the month
int daysInMonth(int m, int y)
{
    if (m == 1) return 31;
    if (m == 2)
    {
        // if leap year  then 29 days
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        {
            return 29;
        }
        else return 28;
    }
    if (m == 3) return 31;
    if (m == 4) return 30;
    if (m == 5) return 31;
    if (m == 6) return 30;
    if (m == 7) return 31;
    if (m == 8) return 31;
    if (m == 9) return 30;
    if (m == 10) return 31;
    if (m == 11) return 30;
    if (m == 12) return 31;
    else return -1;
}
void printCalendar(char *month, int year, int startDay, int days)
{
     // print header of calendar
    printf("\nCalendar of %i\n\n", year);

    for (int i = 0; i < (33 - strlen(month)) / 2; i++)
    {
        printf("-");
    } 
    month[0] = toupper(month[0]);
    printf("%s", month);
    // print remainder of dashes depending on string length of month
    for (int i = 0; i < (33 - strlen(month)) / 2; i++)
    {
        printf("-");
    }
    // print extra dash if string length is odd
    if (strlen(month) % 2 == 0) printf("-");
    printf("\n");
    
    // print days of the week
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    
    // keeps track of when to do a new line
    int fullWeek = 0;
    
    // padding for start of month
    printf(" ");
    for (int i = 0; i < startDay; i++)
    {
        printf("     ");
        fullWeek++;
    }
    
    // days in the month
    for (int i = 1; i <= days; i++)
    {
        if (i < 10)
        {
            printf(" %i   ", i);
        }
        else printf("%i   ", i);
        fullWeek++;
        if (fullWeek == 7 && i != days)
        {
            printf("\n");
            printf(" ");
            fullWeek = 0;
        }
    }
    printf("\n\n");
}
