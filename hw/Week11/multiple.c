#include <stdio.h>

int isValid(int a, int b, int c);
int hasSameDigit(int num_array[9]);

int main(void)
{
    int n;
    scanf("%d", &n);

    if (n > 3)
    {
        printf("0, 0, 0\n");
        return 1;
    }

    int result[5][3];
    int count = 0;
    int start = n * 100;
    int end = start + 100;
    for (int i = start; i < end; i++)
    {
        int a = i;
        int b = i * 2;
        int c = i * 3;
        if (isValid(a, b, c) == 1)
        {
            result[count][0] = a;
            result[count][1] = b;
            result[count][2] = c;
            count += 1;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d,%d,%d\n", result[i][0], result[i][1], result[i][2]);
    }
}

int isValid(int a, int b, int c)
{
    int count = 0;
    int num_array[9] = {0};
    for (int i = 0; i < 3; i++)
    {
        int digit_a = a % 10;
        a /= 10;
        int digit_b = b % 10;
        b /= 10;
        int digit_c = c % 10;
        c /= 10;

        if (digit_a == 0 || digit_b == 0 || digit_c == 0)
        {
            return 0;
        }

        num_array[count] = digit_a;
        num_array[count + 1] = digit_b;
        num_array[count + 2] = digit_c;
        count += 3;
    }

    if (hasSameDigit(num_array) == 1)
    {
        return 0;
    }

    return 1;
}

int hasSameDigit(int num_array[9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (num_array[i] == num_array[j])
            {
                return 1;
            }
        }
    }

    return 0;
}