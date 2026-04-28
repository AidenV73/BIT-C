#include <stdio.h>

int countStep(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    int result = countStep(n);

    printf("%d\n", result);
}

// Return step count from 0 -> n
int countStep(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    else if (n == 0)
    {
        return 0;
    }

    else
    {
        return countStep(n - 1) + countStep(n - 2);
    }
}