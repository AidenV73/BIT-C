#include <stdio.h>

int getFactor(int factorPtr, char num[]);

int main(void)
{
    char num[100];

    char ch;
    int dotPtr;
    int hasDot = 0;
    int i = 0;

    int factorPtr;

    while ((ch = getchar()) != '\n')
    {
        if(ch == '.')
        {
            hasDot = 1;
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

    if (hasDot == 0)
    {
        dotPtr = i - 1;
    }

    int factor = getFactor(factorPtr, num);

    dotPtr += factor;


    for (int j = 0; j < dotPtr; j++)
    {
        if (j >= i - 1)
        {
            printf("0");
        }

        else 
        {
            printf("%c", num[j]);
        }
    }
    
    int avail_num = 0;

    if (dotPtr <= 0)
    {
        // Print the first '0'
        printf("0.");

        // Print the rest 0
        while (dotPtr < 0 && avail_num < 8)
        {
            printf("0");
            dotPtr++;
            avail_num++;
        }
    }

    else
    {
        printf(".");
    }
    
    int ptr = dotPtr;
    while (ptr < factorPtr && avail_num < 8)
    {
        printf("%c", num[ptr]);
        avail_num++;
        ptr++;
    }

    for (int i = 0; i < 8 - avail_num; i++)
    {
        printf("0");
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
