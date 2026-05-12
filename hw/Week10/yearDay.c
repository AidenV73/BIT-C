#include <stdio.h>

int isLeapYear(int year);
int countDay(int year, int month, int day);
int year_day(int year);

int main(void)
{
    int start_year, start_month, start_day;

    scanf("%d %d %d", &start_year, &start_month, &start_day);

    int end_year, end_month, end_day;

    scanf("%d %d %d", &end_year, &end_month, &end_day);

    int day_count = 0;

    if (start_year == end_year)
    {
        day_count += (countDay(end_year, end_month, end_day) - countDay(start_year, start_month, start_day));
    }

    else 
    {
        // Add current year 
        day_count += (year_day(start_year) - countDay(start_year, start_month, start_day));

        // Add year between
        for (int i = start_year + 1; i < end_year; i++)
        {
            day_count += year_day(i);
        }

        // Add end year
        day_count += countDay(end_year, end_month, end_day);
    }

    if (day_count == 1)
    {
        printf("%d day\n", day_count);
        return 0;
    }
    printf("%d days\n", day_count);
    return 0;

}   


// Return 1 if current year is leap year, else return 0
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }

    else 
    {
        return 0;
    }
}

// Return dayCount of year from 1 Jan
int countDay(int year, int month, int day)
{
    int dayCount = day;
    int dayMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year) == 1 && month > 2)
    {
        dayCount += 1;
    }

    for (int i = 0; i < (month - 1); i++)
    {
        dayCount += dayMonth[i];
    }

    return dayCount;
}

// Return how many days that current day have
int year_day(int year)
{
    if (isLeapYear(year) == 1)
    {
        return 366;
    }

    else 
    {
        return 365;
    }
}