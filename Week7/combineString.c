#include <stdio.h>

int main(void)
{
    char a[100], b[100];
    scanf("%s %s", a, b);

    char result[200];
    
    int index = 0;
    int i = 0;
    int j = 0;
    // Compare a[i] and b[j] 
    // Put the smaller one into result and index + 1
    while ((a[i] != '\0') && (b[j] != '\0'))
    {
        if (a[i] > b[j])
        {
            result[index] = b[j];
            j += 1;
            index += 1;
        }

        else if (a[i] < b[j])
        {
            result[index] = a[i];
            i += 1;
            index += 1;
        }

        else 
        {
            result[index] = a[i];
            i += 1;
            index += 1;
            result[index] = b[j];
            index += 1;
            j += 1;
        }
    }

    // Add the rest (a or b)
    while (a[i] != '\0')
    {
        result[index] = a[i];
        index += 1;
        i += 1;
    }

    while (b[j] != '\0')
    {
        result[index] = b[j];
        index += 1;
        j += 1;
    }

    result[index] = '\0';

    printf("%s\n", result);
    return 0;
}