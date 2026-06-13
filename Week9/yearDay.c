
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
  
// 声明函数原型  
int leap_year( int );     
int year_days( int );     
int days(int,int,int);    
  
int leap_year( int year )   // 判断闰年或平年  
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;  
}  
  
int year_days(int year)     // 计算一整年的天数  
{   return leap_year( year ) ? 366 : 365;  
}  
  
int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天  
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;  
      
    if  ( leap_year( year ) && month >2 )  
        day++;  
      
    for ( i=1; i<month; i++ )  
        day += months[i];  
  
    return day;  
}  
int main() 
{   
    int start_year, start_month, start_day;

    scanf("%d %d %d", &start_year, &start_month, &start_day);

    int end_year, end_month, end_day;

    scanf("%d %d %d", &end_year, &end_month, &end_day);

    int day_total = 0;


    // Add next year until end_year - 1
    for (int i = start_year + 1; i < end_year; i++)
    {
        day_total += year_days(i);
    }

    // If same year then do minus
    if (start_year == end_year)
    {
        day_total += days(end_year, end_month, end_day) - days(start_year, start_month, start_day);
    }

    else
    {
        day_total += days(end_year, end_month, end_day) + year_days(start_year) - days(start_year, start_month, start_day);
    }

    printf("%d days\n", day_total);
    return 0; 
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  