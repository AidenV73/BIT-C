#include <stdio.h>

int powerOfTwo(int power);

int main(void)
{
    int row[6];

    int count;
    for(count = 0; count < 6; count++)
    {
        scanf("%d", &row[count]);
        if (row[count] == 0)
        {
            break;
        }
    }
    
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        int power = row[i] - 1;
        result += powerOfTwo(power);
    }

    printf("%d\n", result);
}

int powerOfTwo(int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= 2;
    }
    return result;
}