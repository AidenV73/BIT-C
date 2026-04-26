#include <stdio.h>

int calculateCode(char code[12]);

int main(void)
{
    char first;
    char firstSet[6];
    char secondSet[6];

    scanf("%c", &first);
    scanf("%s", firstSet);
    scanf("%s", secondSet);

    // Combine three of the set
    char code[12];
    
    // Append first code
    code[0] = first;

    // Append the first and second
    for (int i = 1; i < 6; i++)
    {
        code[i] = firstSet[i - 1];
        code[5 + i] = secondSet[i - 1];
    }

    code[11] = '\0';
    
    int result = calculateCode(code);

    printf("%d\n", result);
}

int calculateCode(char code[12])
{
    int odd_count = 0;
    int even_count = 0;

    for (int i = 0; i < 12; i += 2)
    {
        int digit = code[i] - '0';
        odd_count += digit;
    }

    for (int i = 1; i < 11; i += 2)
    {
        int digit = code[i] - '0';
        even_count += digit;
    }

    odd_count = odd_count * 3;

    int total_count = odd_count + even_count;

    total_count -= 1;

    int last_digit = total_count % 10;

    int result = 9 - last_digit;

    return result;
}