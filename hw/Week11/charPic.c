#include <stdio.h>

void printSpace(int count);
char addChar(char c, int n);

int main(void)
{
    char c;
    int height;

    scanf("%c %d", &c, &height);

    // Print first line
    printf("%c", c);
    printSpace(4 * (height - 2) + 3);
    printf("%c\n", c);

    // Print mid 
    for (int i = 0; i < height - 2; i++)
    {
        char firstChar = addChar(c, ((2 * (height - 1) + (height - 2)) - i));
        printf("%c", firstChar);
        printSpace(2 * i + 1);
        char secondChar = addChar(c, i + 1);
        printf("%c", secondChar);
        printSpace((4 * (height - 2) + 3) - (4 * (i + 1)));
        printf("%c", secondChar);
        printSpace(2 * i + 1);
        printf("%c\n", firstChar);
    }

    // Print last line (first half)
    for (int i = 0; i < height; i++)
    {
        char ch = addChar(c, 2 * (height - 1) - i);
        printf("%c ", ch);
    }

    // Print last line (second half)
    for (int i = 0; i < height - 1; i++)
    {
        char ch = addChar(c, height + i);
        if (i == height - 2)
        {
            printf("%c\n", ch);
        }
        else 
        {
            printf("%c ", ch);
        }
    }
}

// Print space
void printSpace(int count)
{
    for (int i = 0; i < count; i++)
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