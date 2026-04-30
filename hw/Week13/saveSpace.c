#include <stdio.h>
#include <string.h>

long long combination(int n, int m);
int encode(char s[]);

int main(void)
{
    int testCount;
    scanf("%d", &testCount);

    int testResults[testCount];

    for (int i = 0; i < testCount; i++)
    {
        char s[11];        

        scanf("%s", s);
        int result = encode(s);

        testResults[i] = result;
    }

    for (int i = 0; i < testCount; i++)
    {
        printf("%d\n", testResults[i]);
    }
}

int encode(char s[])
{
    int len = strlen(s);

    // Count how many string with len - 1
    int first_part = 0;
    for (int i = 1; i < len; i++)
    {
        first_part += combination(26, i);
    }

    // Count how many string with len but smaller
    int second_part = 0;
    // For every position
    for (int i = 0; i < len; i++)
    {
        int current = s[i] - 'a';
        int prev;
        if(i == 0)
        {
            prev = -1;
        }

        else
        {
            prev = s[i - 1] - 'a';
        }

        // For every char from prev ~ current
        for (int j = prev + 1; j < current; j++)
        {
            second_part += combination(25 - j, len - i - 1);
        }
    }

    return first_part + second_part + 1;
}

// Pick C (n, m) from n things take m combination
long long combination(int n, int m) 
{
    if (m == 0 || n == m)
    {
        return 1;
    }
    
    int result = 1;

    for (int i = 1; i <= m; i++)
    {
        result = result * (n - m + i) / i;
    }

    return result;
}