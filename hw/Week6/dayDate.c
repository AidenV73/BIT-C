#include <stdio.h>

int countCurrentMonthDay(int year, int month);
int isLeap(int year);

int main(void)
{
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    int n;
    scanf("%d", &n);

    int dayToAdd = n + day;
    while (dayToAdd > countCurrentMonthDay(year, month))
    {
        dayToAdd -= countCurrentMonthDay(year, month);
        month += 1;
        if (month > 12)
        {
            month = 1;
            year += 1;
        }
    }
    printf("%d.%d.%d\n", year, month, dayToAdd);
    return 0;
}

int countCurrentMonthDay(int year, int month)
{
    int currentMonthDay;
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        currentMonthDay = 31;
    }

    if (month == 2)
    {
        if (isLeap(year) == 1)
        {
            currentMonthDay = 29;
        }

        else 
        {
            currentMonthDay = 28;
        }
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        currentMonthDay = 30;
    }

    return currentMonthDay;
}


int isLeap(int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    {
        return 1;
    }
    return 0;
}