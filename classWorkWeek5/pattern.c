#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    int hundred_count = n / 100;
    int ten_count = ((n / 10) % 10);
    int one_count = n % 10;

    // Print hundred "B"
    for (int i = 0; i < hundred_count; i++)
    {
        printf("B");
    }

    for (int i = 0; i < ten_count; i++)
    {
        printf("S");
    }

    for (int i = 0; i < one_count; i++)
    {
        printf("%d", (i + 1));
    }

    printf("\n");

    return 0;
}