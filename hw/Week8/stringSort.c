#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[5][255];

    for (int i = 0; i < 5; i++)
    {
        scanf("%s", s[i]);
    }

    // Bubble sort
    char tmp[255];
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            if (strcmp(s[i], s[j]) < 0) // If < then swap
            {
                strcpy(tmp, s[j]);
                strcpy(s[j], s[i]);
                strcpy(s[i], tmp);
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", s[i]);
    }
    
}