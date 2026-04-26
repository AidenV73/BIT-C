#include <stdio.h>

int main(void)
{
    // Get user input
    int n;
    scanf("%d", &n);

    // Print result
    // Print col
    // Set a variable start from 
    int v = 1;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (v >= 10)
            {
                printf(" %d", v);
            }
            
            else
            {
                printf("  %d", v);
            }
            v += 1;
        }
        printf("\n");
    }

    return 0;

}