#include <stdio.h>

int isBlackFriday(int year, int month);
int yearDay(int year, int month, int day);
int countLeap(int year);
int isLeap(int year);

int main(void)
{
    int year;

    scanf("%d", &year);

    int black_friday_count = 0;

    int black_friday_month[10] = {0};

    for (int month = 1; month < 13; month++)
    {
        if ((isBlackFriday(year, month)) == 1)
        {
            black_friday_month[black_friday_count] = month;
            black_friday_count += 1;
        }
    }

    if (black_friday_count > 1)
    {
        printf("There are %d Black Fridays in year %d.\n", black_friday_count, year);
    }

    else 
    {
        printf("There is %d Black Friday in year %d.\n", black_friday_count, year);
    }

    if (black_friday_count != 0)
    {
        if (black_friday_count == 1)
        {
            printf("It is:\n");
        }

        else
        {
            printf("They are:\n");            
        }

        for (int i = 0; i < 10; i++)
        {
            if (black_friday_month[i] == 0)
            {
                break;
            }
            
            else
            {
                printf("%d/%d/13\n", year, black_friday_month[i]);
            }
        }
    }
}

// Return 1 if the day is black friday, else return 0
int isBlackFriday(int year, int month)
{
    if ((yearDay(year, month, 13)) == 5)
    {
        return 1;
    }
    return 0;
}

int yearDay(int year, int month, int day) 
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
    year = year - 1;
    int divide_four_count = (year / 4) - (1899 /4);
    int divide_hundred_count = (year / 100) - (1899 / 100);
    int divide_fourHundred_count = (year / 400) - (1899 / 400);
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
