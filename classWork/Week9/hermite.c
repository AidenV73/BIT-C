#include <stdio.h>

int hermite(int n, int x);

int main(void)
{
    int n, x;
    scanf("%d %d", &n, &x);

    int result = hermite(n, x);

    printf("%d\n", result);
}

int hermite(int n, int x)
{
    if (n == 0)
    {
        return 1;
    }

    else if (n == 1)
    {
        return (n * 2);
    }

    int expression_1 = 2 * x * hermite(n - 1, x);
    int expression_2 = 2 * (n - 1) * hermite(n - 2, x);
    
    return expression_1 - expression_2;
}