#include <stdio.h>

void printSpace(int i);
int printIncreaseNumber(int i);
void printDecreaseNumber(int start, int i);

int main(void)
{
    int n;
    scanf("%d", &n);

    printSpace((2 * n) - 1);
    printf("1\n");
    for (int i = 1; i < n; i++)
    {
        printSpace((2 * n) - 1 - (2 * i));
        int start = printIncreaseNumber(i);
        printDecreaseNumber(start, i);
        printf("\n");
    }
    return 0;
}

void printSpace(int i)
{
    for (int _ = 0; _ < i; _++)
    {
        printf(" ");
    }
}

int printIncreaseNumber(int i)
{
    // Start at number n
    int n = 1;
    printf("%d ", n);
    for (int _ = 0; _ < i; _++)
    {
        n += 1;

        printf("%d ", n);
    }

    return n;
}

void printDecreaseNumber(int start, int i)
{
    for (int _ = 0; _ < i; _++)
    {
        start -= 1;
        if (_ == (i - 1))
        {
            printf("%d", start);
        }
        else
        {
            printf("%d ", start);
        }
    }
}