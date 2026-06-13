#include <stdio.h>

int isEven(int n);
int calculateResult(int row, int col, int n);

int main(void)
{
    // Get user input
     int n;
     scanf("%d", &n);

    // Iterate every row and col and calculate num
    for (int row = 0; row < n; row++)
    {   
        for (int col = 0; col < n; col++)
        {
            int result = calculateResult(row, col, n);
            if (col == (n - 1))
            {
                if (result < 10)
                {
                    printf(" %d", result);
                }
                else
                {
                    printf("%d", result);
                }
            }
            else 
            {
                if (result < 10)
                {
                    printf(" %d ", result);
                }
                else
                {
                    printf("%d ", result);
                }
            }
        }
        printf("\n");
    }

    return 0;
}

int isEven(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    return 0;
}

int calculateResult(int row, int col, int n)
{
    int k = row + col;
    int base;
    int offset;
    if (k <= n)
    {
        base = ((k * (k + 1)) / 2);
    }

    else 
    {
        base = ((n * (n + 1)) / 2);
        // Calculate how many line need to be add
        int count = k - n;
        // Count of the first diaognal
        int first = n - 1;
        int last = first - (count - 1); // Not include self so must +1

        base += (count * (first + last)) / 2;
    }

    if (isEven(k) == 0)                 
    {
        if (k < n)
        {
            // Offset starts from row = 0
            offset = row;
        }
        
        else 
        {
            // Offset starts from row = k - n + 1
            offset = row - (k - n + 1);
        }
    }

    else                             
    {
        if (k < n)
        {
            // Start at col = 0
            offset = col;
        }

        else 
        {
            // Start at col = k - n + 1
            offset = col - (k - n + 1);
        }
    }

    return base + 1 + offset;
}