#include <stdio.h>

int findSmallest(int array[100]);

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

    head[head_count] = 0;

    // Get warrior info
    int warrior[warrior_count];

    for (int i = 0; i < warrior_count; i++)
    {
        scanf("%d", &warrior[i]);
    }

    warrior[warrior_count] = 0;

    // Set a score
    int score = 0;

    // Find the smallest and compare
    while ((head_count > 0) && (warrior_count > 0))
    {
        int smallest_head = findSmallest(head);
        int smallest_warrior = findSmallest(warrior);

        head_count -= 1;
        warrior_count -= 1;

        // If warrior >= head then add score and find new smallest 
        if (smallest_warrior >= smallest_head)
        {
            score += smallest_warrior;
        }

        else 
        {
            // Find new warrior
            while (warrior_count > 0)
            {
                smallest_warrior = findSmallest(warrior);
                warrior_count -= 1;

                // If found then jump out loop and find new smallest
                if (smallest_warrior >= smallest_head)
                {
                    score += smallest_warrior;
                    break;
                }
            }
        }
    }

    if (head_count > 0)
    {
        printf("bit is doomed!\n");
        return 1;
    }

    printf("%d\n", score);
    return 0;
    
}

// Find the smallest number in the array and remove it 
int findSmallest(int array[100])
{
    int smallest = array[0];
    int smallest_index = 0;
    int i = 0;
    // Find the smallest number 
    for (i = 1; ((i < 100) && array[i] != 0); i++)
    {
        // If array[i] < current smallest then update smallest
        if (array[i] < smallest)
        {
            // Update smallest 
            smallest = array[i];
            smallest_index = i;
        }
    }

    // Remove the smallest number
    for (int j = smallest_index; j < (i - 1); j++)
    {
        array[j] = array[j+1];
    }

    array[i-1] = 0;

    return smallest;
}