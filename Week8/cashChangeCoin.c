#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    // Proportion of 1 yuan : 0.5 yuan : 0.1 yuan = 9 : 12 : 10
    // 8t = 5n (Mathematical problem :) )
    // If 5n / 8 not integer then no exchange (t must be an integer)
    int oneCashCount, fiveCoinCount, oneCoinCount;
    if (((5 * n) % 8) == 0)
    {
        int t = (5 * n) / 8;
        oneCashCount = 9 * t;
        fiveCoinCount = 12 * t;
        oneCoinCount = 10 * t;
        printf("%d,%d,%d\n", oneCoinCount, fiveCoinCount, oneCashCount);
    }
    else 
    {
        printf("No change.\n");
    }
    
}