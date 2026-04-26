#include <stdio.h>

int main(void)
{
    // Get user input
    int height;
    scanf("%d", &height);

    // Print the result
    int first = (2 * height) - 1;
    // Print first line
    for (int i = 0; i < first; i++)
    {
        printf("*");
    }

    printf("\n");

    // Print the hollow part
    for (int i = 0; i < (height - 2); i++)
    {
        // Print space
        for (int j = 0; j < (i + 1); j++)
        {
            printf(" ");
        }

        // Print one star
        printf("*");

        // Print space inside triangle
        for (int k = 0; k < (first - (2 * (i + 2))); k++)
        {
            printf(" ");
        }

        // Print star
        printf("*");

        printf("\n");
    }

    // Print the last star
    for (int i = 0; i < (height - 2); i++)
    {
        printf(" ");
    }
    if (height == 1)
    {
        return 0;
    }
    printf(" *\n");
    return 0;
}