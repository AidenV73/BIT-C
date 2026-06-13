#include <stdio.h>

int main(void)
{
    int day;
    scanf("%d", &day);
    
    if (day == 1)
    {
        printf("The monkey got 1 peach in first day.\n");
        return 0;
    }
    // current is the day when banana left 1
    int currentCount = 1;
    int yesterdayCount;

    for (int i = day - 1; i > 0; i--)
    {
        yesterdayCount = 2 * (currentCount + i);
        currentCount = yesterdayCount;
    }

    printf("The monkey got %d peaches in first day.\n", currentCount);
    return 0;
}