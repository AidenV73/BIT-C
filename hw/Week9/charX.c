#include <stdio.h>

void printSpace(int i);
char addChar(char c, int n);

int main(void)
{
    int height;
    char c;
    
    scanf("%d %c", &height, &c);

    // Calculate char starting point
    c = addChar(c, height - 1);

    // Print top
    for (int i = 0; i < (height - 1); i++)
    {
        // Print first space
        printSpace(i);

        // Print char
        printf("%c", c);

        // Print middle space
        printSpace((2 * (height - 1)) - ((2 * i) + 1)); 

        // Print char
        printf("%c", c);

        // Update char 
        c = addChar(c, -1);

        printf("\n");
    }

    // Print mid
    printSpace(height - 1);
    printf("%c\n", c);

    c = addChar(c, -1);

    // Print last
    for (int i = 0; i < (height - 1); i++)
    {
        // Print first space
        printSpace(height - 2 - i);
        
        // Print char
        printf("%c", c);

        // Print middle space
        printSpace((2 * i) + 1);

        // Print char
        printf("%c", c);

        // Update char
        c = addChar(c, -1);
        printf("\n");
    }
}

// Print space
void printSpace(int i)
{
    if (i == 0)
    {
        return;
    }

    else 
    {
        printf(" ");

        printSpace(i - 1);
    }
}

// Return char after adding 
char addChar(char c, int n)
{
    c += n;

    // c less than 'A' (65)
    if (c < 65)
    {
        return 'Z' - (64 - c);
    }

    // c greater than 'Z' (90)
    else if (c > 90)
    {
        return 'A' + (c - 91);
    }

    else 
    {
        return c;
    }
}