#include <stdio.h>

int numberProcess(int n, int i);
void printSpace(int i);

int main(void)
{
    int start, row;
    scanf("%d %d", &start, &row);

    if (row == 1)
    {
        printf("%d\n", start);
        return 1;
    }

    // Print the first row
    for (int i = 0; i < row; i++)
    {
        printf("%d", start);
        start = numberProcess(start, 1);
    }

    printf("\n");

    int lastNum = numberProcess(start, row - 2);

    // Print the middle part
    for (int i = 0; i < (row - 2); i++)
    {
        int front = numberProcess(lastNum, (row - 2 - i));
        printf("%d", front);

        printSpace((row - 3) - i);

        int last = numberProcess(start - 1, i + 1);
        printf("%d", last);
        printf("\n");
    }

    // Print the last line
    printf("%d\n", lastNum);

}

int numberProcess(int n, int i)
{
    n += i;
    return (n % 10);
}

void printSpace(int i)
{
    for (int _ = 0; _ < i; _++)
    {
        printf(" ");
    }
}