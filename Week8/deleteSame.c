#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[101];

    scanf("%s", s);

    char result[101];

    int len_s = strlen(s);
    int count = 0;

    for (int i = 0; i < len_s; i++)
    {
        char c = s[i];
        int isNew = 1; // 1 is true 0 is false
        // If c is not in result then add into 
        for (int j = 0; j < (count + 1); j++)
        {
            char target = result[j];
            if (c == target)
            {
                isNew = 0;
                break;
            }
        }
        if (isNew == 1)
        {
            result[count] = c;
            count += 1;
        }
    }

    result[count] = '\0';
    printf("%s\n", result);
}