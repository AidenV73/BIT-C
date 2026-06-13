#include <stdio.h>

int main(void)
{
    int day[7];
    for (int i = 0; i < 7; i++)
    {
        int study_hour, work_hour;
        scanf("%d %d", &study_hour, &work_hour);
        int total_hour = study_hour + work_hour;
        day[i] = total_hour;
    }

    int unhappy_day = 0;
    int max = day[0];
    for (int i = 1; i < 7; i++)
    {
        if (day[i] > max)
        {
            max = day[i];
            unhappy_day = i;
        }
    }

    if (max >= 10)
    {
        printf("%d\n", unhappy_day + 1);
    }

    else 
    {
        printf("0\n");
    }

    return 0;
}