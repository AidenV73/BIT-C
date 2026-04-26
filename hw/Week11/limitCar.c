#include <stdio.h>

int get_total_days(int year, int month, int day);
int isLeapYear(int year);
int countDay(int year, int month, int day);
int year_day(int year);

int main(void)
{
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);

    int total_days = get_total_days(year, month, day);
    
    int arr[5] = {38, 49, 50, 16, 27};
    
    // Which period
    int period = total_days / (13 * 7);
    
    // How many days in period
    int day_in_cycle = total_days % (13 * 7);

    // Which day (0 ~ 6 Sun ~ Sat)
    int day_of_week = total_days % 7;

    if (day_of_week == 0 || day_of_week == 6)
    {
        printf("Free.\n");
        return 1;
    }

    int num1 = arr[(day_of_week - 1 + (period * 5) - period) % 5] / 10;
    int num2 = arr[(day_of_week - 1 + (period * 5) - period) % 5] % 10;
    
    printf("%d and %d.\n", num1, num2);

}

// Return total day from 2012 4 9
int get_total_days(int year, int month, int day)
{
    int total = 0;

    if (year == 2012)
    {
        total += (countDay(year, month, day) - 99);
    }

    else 
    {
        // Add current year
        total += 267;

        // Add year between
        for (int i = 2012 + 1; i < year; i++)
        {
            total += year_day(i);
        }

        // Add end year
        total += countDay(year, month, day);
    }

    return total;
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
 