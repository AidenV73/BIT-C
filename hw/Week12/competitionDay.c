#include <stdio.h>

int countDay(int team_count);

int main(void)
{
    int test_count;

    scanf("%d", &test_count);

    int result[test_count];

    for (int i = 0; i < test_count; i++)
    {
        int team_count;

        scanf("%d", &team_count);

        result[i] = countDay(team_count);
    }

    for (int i = 0; i < test_count; i++)
    {
        printf("%d\n", result[i]);
    }
    
    return 0;
}

// Return how many day needed for all team
int countDay(int team_count)
{
    int count;

    if (team_count == 1)
    {
        count = 0;
    }

    else if (team_count % 2 == 0)
    {
        count = team_count - 1;
    }

    else
    {
        count = team_count;
    }

    return count;
}