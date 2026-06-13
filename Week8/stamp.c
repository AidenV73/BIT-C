#include <stdio.h>

int main(void)
{
    int stamps[4];

    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &stamps[i]);
    }

    int dp[100];
    dp[0] = 0;
    for (int i = 1; i < 100; i++)
    {
        dp[i] = 999;
    }
    
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int stamp_val = stamps[j];
            if (i >= stamp_val)
            {
                if ((dp[i - stamp_val] + 1) < dp[i])
                {
                    dp[i] = dp[i - stamp_val] + 1;
                }
            }
        }
    }

    int counter = 0;
    int i = 1;
    while (dp[i] <= 5)
    {
        counter += 1;
        i += 1;
    }

    printf("The max is %d.\n", counter);
}