#include <stdio.h>
#include <string.h>

int main(void)
{
    int student_count;
    
    scanf("%d", &student_count);

    char names[student_count][21];
    int result[student_count];

    for (int i = 0; i < student_count; i++)
    {
        scanf(" %20[^,],%d", names[i], &result[i]);
    }

    // Bubble sort
    for (int i = 0; i < student_count; i++)
    {
        for (int j = 0; j < student_count - 1 - i; j++)
        {
            if (result[j] < result[j + 1])
            {
                // Score swap
                int tmp = result[j + 1];
                result[j + 1] = result[j];
                result[j] = tmp;

                // Name swap
                char tmpName[21];
                strcpy(tmpName, names[j + 1]);
                strcpy(names[j + 1], names[j]);
                strcpy(names[j], tmpName);
            }
        }
    }

    // Print result
    for (int i = 0; i < student_count; i++)
    {
        printf("%s,%d\n", names[i], result[i]);
    }

    return 0;
}