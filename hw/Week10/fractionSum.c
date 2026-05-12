#include <stdio.h>

double sumCalculate(int n);

int main(void)
{
    int n;

    scanf("%d", &n);

    double result = sumCalculate(n);
    
    printf("sum=%.6f\n", result);
}

double sumCalculate(int n)
{
    if (n == 1)
    {
        return 1.0;
    }

    else 
    {
        return (1.0 / n) + sumCalculate(n - 1);
    }
}