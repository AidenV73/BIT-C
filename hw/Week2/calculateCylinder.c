#include <stdio.h>

int main(void) 
{
    double pi = 3.1415926;
    // Get radius and height
    double radius, height;
    scanf("%lf %lf", &radius ,&height);

    // Calculate lateral area and volume of Cylinder
    double lateral_area = 2 * pi * radius * height;
    double volume = pi * (radius * radius) * height;

    // Printout the result
    printf("s=%.2lf,v=%.2lf\n", lateral_area, volume);

    return 0;
}