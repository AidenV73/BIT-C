#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    // Get user input
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // If a = 0 then only one answer
    if (a == 0) 
    {
        if (b == 0) 
        {
            printf("Input error!\n");
            return 2;
        }
        double ans = 0 - (double)c / b;
        printf("x=%.6lf\n", ans);
        return 0;
    }


    // Check if it is solvable
    int solvable_num = (b * b) - (4 * a * c);

    if (solvable_num < 0) {
        // If b == 0
        if (b == 0)
        {
            double ans1, ans2;
            ans1 = sqrt(abs(c / a));
            ans2 = -ans1;
            printf("x1=%.6lfi\n", ans1);
            printf("x2=%.6lfi\n", ans2);
            return 0;
        }
        
        else
        {
            // Seperate into (-b / 2a) +- (sqrt(b^2-4ac))
            double first, second;
            first = -((double)b / (2 * a));
            second = sqrt(abs(solvable_num)) / (2 * a);
            printf("x1=%.6lf+%.6lfi\n", first, second); 
            printf("x2=%.6lf-%.6lfi\n", first, second); 
            return 3;
        }
    }

    if (solvable_num == 0) 
    {
        double ans = - b / (2 * a);
        printf("x1=x2=%.6lf\n", ans);
        return 0;
    }

    double ans1, ans2;
    ans1 = (-b + sqrt(solvable_num)) / (2 * a);
    ans2 = (-b - sqrt(solvable_num)) / (2 * a);

    printf("x1=%.6lf\n", ans1);
    printf("x2=%.6lf\n", ans2);
    return 0;
}