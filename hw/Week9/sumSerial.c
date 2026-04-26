#include <stdio.h>

float calculateResult(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    float result = calculateResult(n);

    printf("%.6f\n", result);
}

float calculateResult(int n)
{
    if (n == 1)
    {
        return 1.0;
    }

    // If n is even then sum
    else 
    {
        float result = 0;
        if (n % 2 == 0) 
        {
            result = (float) 1 / n;
        }

        else 
        {
            result = (float) -1 / n;
        }

        return result + calculateResult(n - 1);
    }
}