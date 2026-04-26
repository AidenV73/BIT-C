#include <stdio.h>

void numberProcess(int count, int numbers[count], int result[count]);

int main(void)
{
    int count;

    scanf("%d", &count);

    int numbers[count];
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int result[count];

    numberProcess(count, numbers, result);

    for (int i = 0; i < ((count + 1) / 2); i++)
    {
        printf("%d ", result[i]);
    }

    printf("\n");
    return 0;
}

void numberProcess(int count, int numbers[count], int result[count])
{
    for (int i = 0; i < (count / 2); i++)
    {
        result[i] = numbers[i] * numbers[count - i - 1];
    }

    if (count % 2 != 0)
    {
        result[count / 2] = numbers[(count / 2)];
    }
}