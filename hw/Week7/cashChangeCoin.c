#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int value = 10 * n;

    // 1 yuan cash count
    // Initialize  value
    int oneCashCount = 0;

    // 0.1 yuan coin count
    int oneCoinCount = 0;

    // 0.5 yuan coin count
    int fiveCoinCount = 0;

    // Iterate 
    for (int i = 0; i < value; i++)
    {
        for (int j = 0; j < value; j++)
        {
            for (int k = 0; k < value; k++)
            {
                if (((i * 4) == (j * 3)) && ((j * 5) == (k * 6))) // Height Same
                {
                    if ( 10 * value == ((10 * i) + (j * 5) + (k * 1))) // Value Same
                    {
                        oneCashCount = i;
                        fiveCoinCount = j;
                        oneCoinCount = k;
                    }
                }
            }
        }
    }

    if (oneCashCount != 0)
    {
        printf("%d,%d,%d\n", oneCoinCount, fiveCoinCount, oneCashCount);
        return 0;
    }
    else 
    {
        printf("No change.\n");
        return 1;
    }
}
