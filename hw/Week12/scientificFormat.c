#include <stdio.h>

int getFactor(int factorPtr, char num[]);

int main(void)
{
    char num[100];

    char ch;
    int dotPtr;
    int i;

    int factorPtr;

    while ((ch = getchar()) != '\n')
    {
        if(ch == '.')
        {
            dotPtr = i;
            continue;
        }

        if (ch == ' ')
        {
            continue;
        }

        if (ch == 'e' || ch == 'E')
        {
            factorPtr = i;
            continue;
        }

        num[i] = ch;
        i++;
    }

    num[i] = '\0';

    int factor = getFactor(factorPtr, num);

    dotPtr += factor;

    for (int j = 0; j < dotPtr; j++)
    {
        printf("%c", num[j]);
    }

    printf(".");

    int ptr = dotPtr;
    while (ptr < factorPtr)
    {
        printf("%c", num[ptr]);
        ptr++;
    }

    printf("\n");
    return 0;
}

// Return factor
int getFactor(int factorPtr, char num[])
{
    int times = 0;
    int isNegative = 0;

    if (num[factorPtr] == '-')
    {
        isNegative = 1;
        factorPtr++;
    }

    while (num[factorPtr] != '\0')
    {
        times = (times * 10) + (num[factorPtr] - '0');
        factorPtr++;
    }

    if (isNegative == 1)
    {
        times = -times;
    }

    return times;
}
