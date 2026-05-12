#include <stdio.h>

void printSpace(int n);
int addNum(int n);

int main(void)
{
    int n; 

    if (scanf("%d", &n) != 1)
    {
        printf("input error\n");
        return 2;
    }

    if (n >= 10)
    {
        printf("input error\n");
        return 1;
    }

    // Length of half shape but not include the mid line
    int length = n - 1;

    int hasOffset = 0;
    // n will grow up to >= 10

    if ((2 * n) - 1 >= 10)
    {
        hasOffset = 1;
    }
    int current_num = 1;
    // Print top
    for (int i = 0; i < length; i++)
    {
        int frontSpaceCount = i;

        if (hasOffset == 1 && current_num < 10)
        {
            frontSpaceCount += 1;
        }

        printSpace(frontSpaceCount);
        printf("%d", current_num);
        printSpace((2 * length) - ((2 * i) + 1));
        printf("%d", current_num);
        current_num = addNum(current_num);
        printf("\n");
    }

    // Print mid
    int midSpaceCount = length;
    if (hasOffset == 1)
    {
        midSpaceCount += 1;
    }
    printSpace(midSpaceCount);
    printf("%d\n", current_num);
    current_num = addNum(current_num);

    // Print last
    for (int i = 0; i < length; i++)
    {
        int frontSpaceCount = length - (i + 1);
        
        if (hasOffset == 1 && current_num < 10)
        {
            frontSpaceCount += 1;
        }

        printSpace(frontSpaceCount);
        printf("%d", current_num);
        printSpace((2 * i) + 1);
        printf("%d", current_num);
        current_num = addNum(current_num);
        printf("\n");
    }

    return 0;
}

int addNum(int n)
{
    n++;
    if (n == 10)
    {
        return 1;
    }

    return n;
}
void printSpace(int n)
{
    if (n == 0)
    {
        return; 
    }

    else 
    {
        printf(" ");
        printSpace(n - 1);
    }
}