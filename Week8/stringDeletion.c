#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[255], s2[255];

    scanf("%s %s", s1, s2);
    // Loop every element in s2
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    for (int i = 0; i < len_s2; i++)
    {
        char c = s2[i]; // Char to be delete
        
        // Check every element in s1 if found then delete
        for (int j = 0; j < len_s1; j++)
        {
            char current = s1[j];
            if (current == c)
            {
                // Do remove
                for (int k = j; k < len_s1; k++)
                {
                    s1[k] = s1[k + 1];
                }
                j -= 1;
            }
        }
    }

    printf("%s\n", s1);
    
    return 0;
}