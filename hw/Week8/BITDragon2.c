#include <stdio.h>

void sortArr(int len, int arr[len]);

int main(void)
{
    int head_count, warrior_count;

    scanf("%d %d", &head_count, &warrior_count);

    // Get head info 
    int head[head_count];

    for (int i = 0; i < head_count; i++)
    {
        scanf("%d", &head[i]);
    }

    // Get warrior info
    int warrior[warrior_count];

    for (int i = 0; i < warrior_count; i++)
    {
        scanf("%d", &warrior[i]);
    }

    // If head_count more than warrior_count then return 
    if (head_count > warrior_count)
    {
        printf("bit is doomed!\n");
        return 1;
    }

    // Sort both of them from small to big
    sortArr(head_count, head);
    sortArr(warrior_count, warrior);

    // Initialize score
    int score = 0;

    // Use two ptr to compare two smallest
    int i = 0;
    int j = 0;

    while (i < head_count && j < warrior_count)
    {
        int smallest_head = head[i];
        int smallest_warrior = warrior[j];

        if (smallest_head <= smallest_warrior)
        {
            score += smallest_warrior;
            i++;
            j++;
        }

        else 
        {
            j++;
        }
    }

    if (score == 0 || i < head_count)
    {
        printf("bit is doomed!\n");
        return 1;
    }

    printf("%d\n", score);
}

void sortArr(int len, int arr[len])
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}