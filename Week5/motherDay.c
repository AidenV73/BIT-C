#include <stdio.h>


int dayCount(int year, int month, int day);
int countLeap(int year);
int isLeap(int year);

int main(void)
{
    // Get user input
    int year;
    printf("");
    scanf("%d", &year);

    // Use findDay function to find first Sunday then add 7
    int day = 0;
    int target = 0;
    for (int i = 0; i < 7; i++)
    {
        day = dayCount(year, 5, i);
        if (day == 0)
        {
            target = i + 7;
        }
    }

    printf("%d\n", target);

    return 0;
}


int dayCount(int year, int month, int day) 
{
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
    
    return mod;

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

