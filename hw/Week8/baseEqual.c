#include <stdio.h>
#include <string.h>

int getMinBase(char n[10]);
int charToDecimal(char c);
int numberDecimal(char n[10], int base);

int main(void)
{
    char a[10], b[10];
    scanf("%s %s", a, b);
    int minBaseA = getMinBase(a);
    int minBaseB = getMinBase(b);

    int resultA;
    int resultB;
    int hasResult = 0;
    
    for (int i = minBaseA; i < 37; i++)
    {
        for (int j = minBaseB; j < 37; j++)
        {
            int numA = numberDecimal(a, i);
            int numB = numberDecimal(b, j);
            if (numA == numB)
            {
                hasResult = 1;
                resultA = i;
                resultB = j;
                break;
            }
        }
    }

    if (hasResult == 1)
    {
        printf("%s (base %d) = %s (base %d)\n", a, resultA, b, resultB);
    }

    else
    {
        printf("%s is not equal to %s in any base 2..36\n", a, b);
    }
}

int getMinBase(char n[10])
{
    int max = charToDecimal(n[0]);
    int i = 1;
    while (n[i] != '\0')
    {
        // Find the largest num
        int num = charToDecimal(n[i]);
        if (num > max)
        {
            max = num;
        }
        i += 1;
    }
    return (max + 1);
}

int charToDecimal(char c)
{
    int result = 0;

    if (c >= '0' && c <= '9')
    {
        result = c - '0';
    }

    if (c >= 'A' && c <= 'Z')
    {
        result = c - 'A' + 10;
    }

    return result;
}


int numberDecimal(char n[10], int base)
{
    int ptr = 0;
    int result = 0;
    while (n[ptr] != '\0')
    {
        int val = charToDecimal(n[ptr]);
        result = ((result * base) + val);
        ptr += 1;
    }

    return result;
}

