#include <stdio.h>

int main(void)
{
    // Get user input
    int n;
    scanf("%d", &n);

    // Find m
    int m = 0;
    int current = 0;
    while (current < n)
    {
        m += 1;
        current += m;
    }

    printf("%d\n", m);
}