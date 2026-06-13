#include <stdio.h>

int sumTotal(int n, int m);

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    int result = sumTotal(n, m);

    printf("The sum from %d to %d is %d.\n", n, m, result);
}

// Return sum from n - m
int sumTotal(int n, int m)
{
    if (n == m)
    {
        return m;
    }

    else 
    {
        return (n + sumTotal(n + 1, m));
    }
}