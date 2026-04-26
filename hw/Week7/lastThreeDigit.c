#include <stdio.h>

int main(void)
{
    int a, n;
    scanf("%d %d", &a, &n);
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= a;
        result = result % 1000;
    }

    if (result == 0)
    {
        printf("The last 3 numbers is 000.\n");
        return 0;
    }

    printf("The last 3 numbers is %d.\n", result);

    return 0;
}