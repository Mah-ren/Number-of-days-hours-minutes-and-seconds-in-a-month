#include <iostream>
#include "Validation.h";

using namespace std;

bool isLeapYear(int);

int   NumberOfMinutesInMonth(short, int);
short NumberOfDaysInMonth(short, int);
short NumberOfDaysInMonthInLeapYear(short, int);
short NumberOfHoursInMonth(short, int);
int   NumberOfSecondsInMonth(short, int);

int main()
{
    int year = 1; short month = 1;
    year = Validation::GetValidPositiveShortIntegerInRange("please enter a year to check: ", 1, 1000000);
    month = Validation::GetValidPositiveShortIntegerInRange("please enter a month to check: ", 1, 12);

    cout << "\nNumber Of Days    in Month[" << month << "] is " << NumberOfDaysInMonth(month, year);
    cout << "\nNumber Of Hours	  in Month[" << month << "] is " << NumberOfHoursInMonth(month, year);
    cout << "\nNumber Of Minutes in Month[" << month << "] is " << NumberOfMinutesInMonth(month, year);
    cout << "\nNumber Of Seconds in Month[" << month << "] is " << NumberOfSecondsInMonth(month, year);


}

bool isLeapYear(int year)
{
    return(year % 4 != 0 && year % 100 != 0 || year % 400 == 0);
}

short NumberOfDaysInMonthInLeapYear(short month, int year)
{
    short array[] = { 1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return array[month];
}

short NumberOfDaysInMonth(short month, int year)
{
    return(isLeapYear(year) && month == 2) ? 29 : NumberOfDaysInMonthInLeapYear(month, year);
}

short NumberOfHoursInMonth(short month, int year)
{
    return NumberOfDaysInMonth(month, year) * 24;
}

int NumberOfMinutesInMonth(short month, int year)
{
    return NumberOfHoursInMonth(month, year) * 60;
}

int NumberOfSecondsInMonth(short month, int year)
{
    return NumberOfMinutesInMonth(month, year) * 60;
}