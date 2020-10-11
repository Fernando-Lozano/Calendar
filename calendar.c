// the object of this program is to display a specific month of a year
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "helpers.h"

int main(void)
{
    char *month = malloc(sizeof(char) * 9);
    int startDay;
    int monthNum;
    int year;
    int days;
    
    printf("This CLI program displays a specified month in any year\n");
    printf("Enter month and year. E.g, January 1996: ");
    scanf("%s %i", month, &year);
    
    // finds the month's number
    monthNum = findMonth(month);
    if (monthNum == -1)
    {
        printf("Typed incorrect month format\n");
        return 1;
    }
    
    // finds numbers of days in the month
    days = daysInMonth(monthNum, year);
    
    // finds the weekday the 1st starts on
    startDay = firstDay(monthNum, year);
    
    // print the calendar month
    printCalendar(month, year, startDay, days);
    
    free(month);
}