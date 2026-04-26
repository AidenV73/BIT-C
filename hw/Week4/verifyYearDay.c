#include <stdio.h>

int countLeap(int year);
int isLeap(int year);
int isLegal(int year, int month, int day);

int main(void) 
{
    // Get user input
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    if (isLegal(year, month, day) == 0)
    {
        return 1;
    }
    // Count day between 1/JAN/1900 and given date (Must consider leap year)    
    int leap_count = countLeap(year);
    int day_count_before = ((year - 1900) * 365) + leap_count;
    int day_count_this_year = 0;
    // Count alr pass how many month
    if (month > 1)
    {
        day_count_this_year += 31;
    }

    if (month > 2)
    {
        if (isLeap(year) == 1)
        {
            day_count_this_year += 29;
        }
        else 
        {
            day_count_this_year += 28;
        }
    }

    if (month > 3)
    {
        day_count_this_year += 31;
    }
    
    if (month > 4)
    {
        day_count_this_year += 30;
    }
    
    if (month > 5)
    {
        day_count_this_year += 31;
    }
    
    if (month > 6)
    {
        day_count_this_year += 30;
    }
    
    if (month > 7)
    {
        day_count_this_year += 31;
    }
    
    if (month > 8)
    {
        day_count_this_year += 31;
    }
    
    if (month > 9)
    {
        day_count_this_year += 30;
    }
    
    if (month > 10)
    {
        day_count_this_year += 31;
    }
    
    if (month > 11)
    {
        day_count_this_year += 30;
    }
    
    day_count_this_year += day;

    int day_count = day_count_before + day_count_this_year;

    // Use mod and print result
    int mod = day_count % 7;
    
    printf("%d\n", mod);
}

int countLeap(int year)
{
    int divide_four_count = ((year - 1) / 4) - (1899 /4);
    int divide_hundred_count = ((year - 1) / 100) - (1899 / 100);
    int divide_fourHundred_count = ((year - 1) / 400) - (1899 / 400);
    int leapCount = divide_four_count - divide_hundred_count + divide_fourHundred_count;
    return leapCount;
}

int isLeap(int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    {
        return 1;
    }
    return 0;
}

int isLegal(int year, int month, int day)
{   
    // If month is not legal
    if (month > 12 || month < 1)
    {
        printf("month is error.\n");
        return 0;
    }

    // If day is not legal
    if (day > 31)
    {
        printf("day is error.\n");
        return 0;
    }

     // If is not leap year but date is 29 Feb
    if (isLeap(year) == 0 && month == 2 && day == 29)
    {
        printf("day is error.\n");
        return 0;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day == 31)
        {
            printf("day is error.\n");
            return 0;
        }
    }

    return 1;
}
