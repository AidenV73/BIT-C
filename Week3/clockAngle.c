#include <stdio.h>

int main(void) 
{
    // Get user input
    int hour, minute;
    scanf("%d %d", &hour, &minute);

    // Calculate the angle
    // Every minute move 6 degree
    float minute_angle = minute * (360.0 / 60);

    // Every hour move 30 degree + Every minute move 0.5 degree
    float hour_angle = (hour * (360 / 12)) + (minute * (30.0 / 60));

    float angle = hour_angle - minute_angle;

    if (angle < 0)
    {
        angle = -angle;
    }

    // Take the smaller angle
    if (angle > 180)
    {
        angle = 360 - angle;
    }

    printf("At %d:%02d the angle is %.1lf degrees.\n", hour, minute, angle);

    return 0;
}