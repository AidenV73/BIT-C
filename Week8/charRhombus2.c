#include <stdio.h>

void printSpace(int i);
char addChar(char c, int n);

int main(void)
{
    char c;
    int height;
    scanf("%c,%d", &c, &height);
    // Print first line
    printSpace(height - 1);
    printf("%c\n", c);
    c = addChar(c, 1);

    // Top
    for (int i = 0; i < (height - 1); i++)
    {
        printSpace((height - 1) - (i + 1));
        printf("%c", c);
        printSpace((2 * i) + 1);
        printf("%c", c);
        c = addChar(c, 1);
        printf("\n");
    }

    // Bottom
    c = addChar(c, -2);
    for (int i = 0; i < (height - 2); i++)
    {
        printSpace(i + 1);
        printf("%c", c);
        printSpace((2 * (height - 2)) - ((2 * i) + 1));
        printf("%c", c);
        c = addChar(c, -1);
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

// Add char
char addChar(char c, int n)
{
    c += ((n + 26) % 26);

    // c less than 'A' (65)
    if (c < 'A')
    {
        return 'Z' - (64 - c);
    }

    // c greater than 'Z' (90)
    else if (c > 'Z')
    {
        return 'A' + (c - 91);
    }

    else 
    {
        return c;
    }
}
