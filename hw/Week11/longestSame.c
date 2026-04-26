#include <stdio.h>

int main(void)
{
    int len;

    scanf("%d", &len);

    int arr[len + 1];

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Make sure it is diff from num infront
    arr[len] = arr[len - 1] + 1;

    int last_start_index = 0;
    int last_end_index = 0;

    int current_start_index = 0;
    int current_end_index = 0;

    while (current_end_index != len + 1)
    {
        int current = arr[current_start_index];

        if (arr[current_end_index] != current)
        {
            // If len longer then update
            int current_len = current_end_index - current_start_index;
            int last_len = last_end_index - last_start_index + 1;

            if (current_len > last_len)
            {
                last_start_index = current_start_index;
                last_end_index = current_end_index - 1;
            }

            // Update start_index
            current_start_index = current_end_index;
        }

        current_end_index++;
    }

    if (last_start_index == last_end_index)
    {
        printf("No equal number list.\n");
        return 1;
    }
   
    printf("The longest equal number list is from %d to %d.\n", last_start_index, last_end_index);
    return 0;
}