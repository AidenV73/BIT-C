#include <stdio.h>

int main(void)
{
    char n[1001];

    scanf("%s", n);

    // Record count of every digit
    int result[10] = {0, 0 , 0, 0, 0, 0, 0, 0, 0}; // Index represent digit

    for (int i = 0; i < 1001; i++)
    {
        if (n[i] == '\0')
        {
            break;
        }
         
        int digit = n[i] - '0';

        result[digit] += 1;
    }

    for (int i = 0; i < 10; i++)
    {
        if (result[i] != 0)
        {
            printf("%d:%d\n", i, result[i]);
        }
    }

    return 0;
}

