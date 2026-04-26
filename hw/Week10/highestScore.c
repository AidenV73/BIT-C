#include <stdio.h>

int findWinner(int scores[10], int result[10]);
void resetArray(int result[10], int winner_count);

int main(void)
{
    int scores[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &scores[i]);
    }

    int result[10];
    int winner_count = findWinner(scores, result);

    for (int i = 0; i < winner_count; i++)
    {
        printf("%d\n", result[i]);
    }
}

// Return winner count and append winner into result
int findWinner(int scores[10], int result[10])
{
    int highest = scores[0];
    result[0] = 1;

    int winner_count = 1;

    for (int i = 1; i < 10; i++)
    {
        int current_score = scores[i];

        if (current_score > highest)
        {
            resetArray(result, winner_count);
            winner_count = 1;
            highest = current_score;
            result[0] = i + 1;
        }

        else if (current_score == highest)
        {
            result[winner_count] = i + 1;
            winner_count += 1;
        }
    }

    return winner_count;
}

void resetArray(int result[10], int winner_count)
{
    for (int i = 0; i < winner_count; i++)
    {
        result[i] = 0;
    }
}
