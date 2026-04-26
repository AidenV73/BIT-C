#include <stdio.h>

int getNumber(int row, int col, int n);
int getLayer(int row, int col, int n);
int min(int a, int b);

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int number = getNumber(row, col, n);
            if (number < 10)
            {
                printf("  ");
            }
            else 
            {
                printf(" ");
            }
            printf("%d", number);
        }
        printf("\n");
    }
    return 0;
}

// Return number by its position 
int getNumber(int row, int col, int n)
{
    // Find out which layer 
    int layer = getLayer(row, col, n);

    // Calculate start number by its layer
    int start = 4 * layer * (n - layer) + 1;

    // Calculate number by its position
    int number;
    int length = n - (2 * layer);

    // If at same line with start number (row == layer)
    if (row == layer)
    {
        number = start + (col - layer);
    }
    
    // If is last col (from up to bottom + row)
    else
    {
        if (col == (n - layer - 1))
        {
            number = start + (length - 1) + (row - layer);
        }

        else 
        {
            // From right to left
            if (row == (n - layer - 1))
            {
                number = start + (length - 1) + (length - 1) + (row - col);
            }

            // From bottom to up
            if (col == layer)
            {
                number = start + (length - 1) + (length - 1) + (length - 1) + (length - 1) - (row - layer);
            }
        }
    }

    return number;
}

// Return layer number by its position
int getLayer(int row, int col, int n)
{
    // Shortest distance to outside is layer
    int toUp = row;
    int toBottom = (n - 1) - row; // total:(n - 1)row
    int toLeft = col;
    int toRight = (n - 1) - col; //total:(n - 1)col

    int layer = min(min(toUp, toBottom), min(toLeft, toRight));
    return layer;
}

// Return the smaller number
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }

    return b;
}