#include <stdio.h>

int isSpecial(int n);
int isError(int n);
int printSpecialEven(int start, int end);

int main(void)
{
    int start[255], end[255];
    int i = 0;
    for (i = 0; i < 255; i++)
    {
        scanf("%d %d", &start[i], &end[i]);
        if ((start[i] == 0) && (end[i] == 0))
        {
            break;
        }
    }

    for (int j = 0; j < i; j++)
    {
        printSpecialEven(start[j], end[j]);
    }

    return 0;
}

int isSpecial(int n)
{
    int num = n;

    while (num > 0)
    {
        int digit = num % 10; // Last digit
        int tmp = num / 10; // Digit before last digit

        // Verify if there is same digit compare to last digit
        while (tmp > 0)
        {
            int tmpLast = tmp % 10; // Last digit of tmp
            if (digit == tmpLast)
            {
                return 0;
            }
            tmp = tmp / 10;
        }

        // Update num to verify the next last digit
        num = num / 10;
    }

    return 1;
}

// If number is odd or number < 0 then is error
int isError(int n)
{

    if (n < 0)
    {
        return 1;
    }

    if ((n < 1000) || (n > 9999))
    {
        return 1;
    }

    return 0;
}

int printSpecialEven(int start, int end)
{
    int counter = 0;
    if ((isError(start) == 1) || ((isError(end) == 1)))
    {
        printf("Error\n");
        return 1; // Error code
    }

    if ((start % 2) == 1)
    {
        start += 1;
    }

    if (start > end)
    {
        printf("Error\n");
        return 2; // Error code
    }

    for (int i = start; i <= end; i += 2)
    {   
        if (isSpecial(i) == 1)
        {
            printf("%d  ", i);
            counter++;
        }
    }
    if (counter != 0)
    {
        printf("\n");
    }
    printf("counter=%d\n", counter);

    return 0;
}