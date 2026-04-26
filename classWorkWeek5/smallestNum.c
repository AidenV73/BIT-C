#include <stdio.h>

int main(void)
{
    int s[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &s[i]);
    }
    
    int start_index;

    // Find the smallest num
    for (int i = 1; i < 10; i++)
    {
        if (s[i] != 0)
        {
            printf("%d", i);
            s[i]--;
            start_index = i;
            break;
        }
    }

    // Print '0'
    for (int i = 0; i < s[0]; i++)
    {
        printf("0");
    }

    // Print the rest
    for (int i = start_index; i < 10; i++)
    {
        for (int j = 0; j < s[i]; j++)
        {
            printf("%d", i);
        }
    }

    printf("\n");
    return 0;

}