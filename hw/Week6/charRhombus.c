#include <stdio.h>

void printSpace(int i);

int main(void)
{
    char c;
    int height;
    scanf("%c %d", &c, &height);
    // Print first line
    printSpace(height - 1);
    printf("%c\n", c);
    c += 1;

    // Top
    for (int i = 0; i < (height - 1); i++)
    {
        printSpace((height - 1) - (i + 1));
        printf("%c", c);
        printSpace((2 * i) + 1);
        printf("%c", c);
        c += 1;
        printf("\n");
    }

    // Bottom
    c -= 2;
    for (int i = 0; i < (height - 2); i++)
    {
        printSpace(i + 1);
        printf("%c", c);
        printSpace((2 * (height - 2)) - ((2 * i) + 1));
        printf("%c", c);
        c -= 1;
        printf("\n");
    }

    // Print last line
    if (height == 1)
    {
        return 0;
    }
    printSpace(height - 1);
    printf("%c\n", c);
    return 0;
}

void printSpace(int i)
{
    for (int _ = 0; _ < i; _++)
    {
        printf(" ");
    }
}
