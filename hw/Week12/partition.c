#include <stdio.h>

int countPartition(int n, int m);

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    int result = countPartition(n, m);

    printf("%d\n", result);
}

// Return count of partition
int countPartition(int n, int m)
{
    if (m == 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    return countPartition(n - m, m) + countPartition(n, m - 1);
}