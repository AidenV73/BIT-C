#include <stdio.h>

void storeDigit(int n, int array[100], int arr_len);
int digitProcess(int digit);

int main(void)
{
    int n;
    int arr[100] = {0};
    int arr_len = 0;

    while (scanf("%d", &n) == 1)
    {
        if (n == 0)
        {
            break;
        }

        // Store every digit
        storeDigit(n, arr, arr_len);

        arr_len += 5;
    }


    int count = arr_len / 5;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int result = digitProcess(arr[(5 * i) + 5 - j - 1]);
            if (j == 4)
            {
                printf("%X\n", result);
            }
            else 
            {
                printf("%X ", result);
            }
        }
    }
    return 0;
}

void storeDigit(int n, int array[100], int arr_len)
{
    for (int i = arr_len; i < arr_len + 5; i++)
    {
        int digit = n % 10;
        array[i] = digit;
        n /= 10;
    }
}

// Digit process (Return decimal and output as base 16)
int digitProcess(int digit)
{
    switch (digit)
    {
        case 0:
            return 125;
            break;
        case 1:
            return 80;
            break;
        case 2:
            return 55;
            break;
        case 3:
            return 87;
            break;
        case 4:
            return 90;
            break;
        case 5:
            return 79;
            break;
        case 6:
            return 111;
            break;
        case 7:
            return 84;
            break;
        case 8:
            return 127;
            break;
        case 9:
            return 94;
            break;
    }
    return 0;
}