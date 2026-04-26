#include <stdio.h>

int main(void)
{
    // Get user input
    int n;
    scanf("%d", &n);

    // Do loop and print stars
    for (int _ = 0; _ < n; _++)
    {
        printf("*");
    }

    printf("\n");

    return 0;
}