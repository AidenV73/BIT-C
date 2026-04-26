#include <math.h>
#include <stdio.h>

double squareroot(double n, double guess, double error);

int main(void)
{
    double n; 
    scanf("%lf", &n);

    double error;
    scanf("%lf", &error);

    double result = squareroot(n, n / 2, error);

    printf("%.8lf\n", result);
}

// Return sqrt of n
double squareroot(double n, double guess, double error)
{
    // If guess is good enough
    if (fabs((guess * guess) - n) < error)
    {
        return guess;
    }

    else 
    {
        return squareroot(n, 0.5 * (guess + (n / guess)), error);
    }
}

