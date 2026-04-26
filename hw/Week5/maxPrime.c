#include <stdio.h>

int isPrime(int n);

int main(void)
{
    // Get user input
    int n;
    printf("");
    scanf("%d", &n);

    if (n == 1)
    {
        printf("The max prime number is 0.\n");
        return 1;
    }

    // 2 is the min prime number
    int max = 2;

    // loop every number
    for (int i = 3; i <= n; i++)
    {
        if (isPrime(i) == 1)
        {
            max = i;
        }
    }

    printf("The max prime number is %d.\n", max);

    return 0;
}

int isPrime(int n)
{
    if (n <= 2)
    {
        return 0;
    }
    if (n % 2 == 0)
    {
        return 0;
    }

    // Always exist i <= sqrt(n), so only need to test till sqrt(n)
    for (int i = 3; i * i <= n; i += 2)
    {
        if ((n % i) == 0)
        {
            return 0;
        }
    }

    return 1;
}