#include <stdio.h>

void printSpaceInvertedTriangle(int i);
int printDecreaseNum(int n, int i);
void printIncreaseNum(int n, int i);
void printSpaceTriangle(int i);

int main(void)
{
    int n;
    scanf("%d", &n);

    // Print the first half
    for (int i = 0; i < (n - 1); i++)
    {
        printSpaceInvertedTriangle(n - (i + 1));
        int nextStart = printDecreaseNum(n, i);
        printIncreaseNum(nextStart, i);
        printf("\n");
    }

    // Print the middle part
    int middleStart = printDecreaseNum(n, n - 1);
    printIncreaseNum(middleStart, n - 1);
    printf("\n");

    // Print the bottom part
    for (int i = 0; i < (n - 1); i++)
    {
        printSpaceTriangle(i + 1);
        int nextStart = printDecreaseNum(n, n - (i + 2));
        printIncreaseNum(nextStart, n - (i + 2));
        printf("\n");
    }
    return 0;
}

// Print Space by invertedTriangle
void printSpaceInvertedTriangle(int i)
{
    for (int _ = 0; _ < i; _++)
    {
        printf("  ");
    }
}

void printSpaceTriangle(int i)
{
    for (int _ = 0; _ < i; _++)
    {
        printf("  ");
    }
}

// Print out number by decreasing n by 1 i times and return the last number
int printDecreaseNum(int n, int i)
{
    int returnNum = n;
    if (returnNum >= 10)
    {
        printf("%d", returnNum);
    }

    else
    {
        printf("%d ", returnNum);
    }
    for (int _ = 0; _ < i; _++)
    {
        returnNum -= 1;
        if (returnNum >= 10)
        {
            printf("%d", returnNum);
        }
        else
        {
            printf("%d ", returnNum);
        }
    }

    return returnNum;
}

// Print out number by increasing n by 1 i times 
void printIncreaseNum(int n, int i)
{
    for (int _ = 0; _ < i; _++)
    {
        n += 1;
        if (n >= 10)
        {
            printf("%d", n);
        }
        else
        {
            printf("%d ", n);
        }
    }
}